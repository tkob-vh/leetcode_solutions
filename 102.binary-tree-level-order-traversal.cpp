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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      if (res.size() <= level) {
        res.resize(level + 1);
      }
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        res[level].push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      level++;
    }
    return res;
  }
};
// @leet end
