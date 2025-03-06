// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
  Node *copyRandomList(Node *head) {
    std::unordered_map<Node *, Node *> map;
    Node *ptr = head;
    while (ptr) {
      map[ptr] = new Node(ptr->val);
      ptr = ptr->next;
    }

    ptr = head;
    while (ptr) {
      map[ptr]->next = map[ptr->next];
      map[ptr]->random = map[ptr->random];
      ptr = ptr->next;
    }
    return map[head];
  }
};
// @leet end
