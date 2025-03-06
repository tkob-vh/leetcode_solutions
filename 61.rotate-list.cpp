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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *dummpy = new ListNode(0, head);
    ListNode *nh = dummpy;
    ListNode *curr = dummpy;

    int i = 0;
    while (curr->next != nullptr) {
      curr = curr->next;
      i++;
    }
    curr->next = head;

    if (k %= i) {
      for (int j = 0; j < i - k; j++) {
        curr = curr->next;
      }
    }

    nh = curr->next;
    curr->next = nullptr;
    return nh;
  }
};
// @leet end
