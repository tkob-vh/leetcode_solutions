// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// #include <vector>
// using namespace std;
// class Node {
// public:
//   int val;
//   vector<Node *> neighbors;
//   Node() {
//     val = 0;
//     neighbors = vector<Node *>();
//   }
//   Node(int _val) {
//     val = _val;
//     neighbors = vector<Node *>();
//   }
//   Node(int _val, vector<Node *> _neighbors) {
//     val = _val;
//     neighbors = _neighbors;
//   }
// };

#include <map>
class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }
    Node *node_cp = new Node(node->val);
    m_map[node->val] = node_cp;
    for (auto n : node->neighbors) {
      auto iter = m_map.find(n->val);
      if (iter != m_map.end()) {
        node_cp->neighbors.push_back(m_map[n->val]);
      } else {
        node_cp->neighbors.push_back(cloneGraph(n));
      }
    }

    return node_cp;
  }

private:
  std::map<int, Node *> m_map;
};
// @leet end
