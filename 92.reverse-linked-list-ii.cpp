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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummp = new ListNode(0);
    dummp->next = head;

    ListNode *former = dummp;
    ListNode *curr = dummp;

    for (int i = 0; i < left - 1; i++) {
      former = former->next;
    }
    curr = former->next;

    for (int i = 0; i < right - left; i++) {
      ListNode *latter = curr->next;
      curr->next = latter->next;
      latter->next = former->next;
      former->next = latter;
    }

    return dummp->next;
  }
};
// @leet end
