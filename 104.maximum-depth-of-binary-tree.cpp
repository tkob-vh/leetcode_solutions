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
#include <algorithm>
#include <cstddef>
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int x = maxDepth(root->left);
    int y = maxDepth(root->right);
    return std::max(x, y) + 1;
  }
};
// @leet end
