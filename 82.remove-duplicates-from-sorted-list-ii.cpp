// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *dummp = new ListNode(-101, head);

    ListNode *prev = dummp;

    while (head != nullptr) {
      while (head->next != nullptr && head->next->val == prev->next->val) {
        head = head->next;
      }
      if (prev->next == head) {
        prev = prev->next;
      } else {
        prev->next = head->next;
      }
      head = head->next;
    }

    return dummp->next;
  }
};
// @leet end
