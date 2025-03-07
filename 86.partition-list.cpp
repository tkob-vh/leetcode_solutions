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
  ListNode *partition(ListNode *head, int x) {
    ListNode *small = new ListNode(0);
    ListNode *large = new ListNode(0);
    ListNode *pt1 = small;
    ListNode *pt2 = large;

    while (head != nullptr) {
      if (head->val < x) {
        pt1->next = head;
        pt1 = pt1->next;
      } else {
        pt2->next = head;
        pt2 = pt2->next;
      }
      head = head->next;
    }

    pt2->next = nullptr;
    pt1->next = large->next;

    return small->next;
  }
};
// @leet end
