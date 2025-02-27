// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    queue<TreeNode *> q;
    q.push(root);

    bool dir = true;
    while (!q.empty()) {
      int size = q.size();
      vector<int> tmp_v(size);

      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        int index = dir ? (size - i - 1) : i;
        tmp_v[index] = node->val;
        if (node->right)
          q.push(node->right);
        if (node->left)
          q.push(node->left);
      }
      dir = !dir;
      res.push_back(tmp_v);
    }
    return res;
  }
};
// @leet end
