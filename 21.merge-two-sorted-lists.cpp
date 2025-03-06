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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    } else if (list2 == nullptr) {
      return list1;
    }

    ListNode *p1 = list1;
    ListNode *p2 = list2;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    if (p1->val <= p2->val) {
      head = p1;
      p1 = p1->next;
    } else {
      head = p2;
      p2 = p2->next;
    }

    tail = head;

    while (p1 && p2) {
      if (p1->val <= p2->val) {
        tail->next = p1;
        p1 = p1->next;
      } else {
        tail->next = p2;
        p2 = p2->next;
      }
      tail = tail->next;
    }

    if (p1 != nullptr) {
      tail->next = p1;
    } else if (p2 != nullptr) {
      tail->next = p2;
    }

    return head;
  }
};
// @leet end
