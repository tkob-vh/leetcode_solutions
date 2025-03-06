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
  ListNode *removeNthFromEnd(ListNode *head, int n) {

    ListNode *dummp = new ListNode(0, head);

    ListNode *prev = dummp;
    ListNode *curr = dummp;

    for (int i = 0; i < n; i++) {
      curr = curr->next;
    }

    while (curr->next) {
      curr = curr->next;
      prev = prev->next;
    }

    prev->next = prev->next->next;

    return dummp->next;
  }
};
// @leet end
