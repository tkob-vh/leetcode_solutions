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
#include <vector>
class Solution {
public:
  // Morris Traversal
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        TreeNode *runner = curr->left;
        while (runner->right)
          runner = runner->right;
        runner->right = curr->right;
        curr->right = curr->left;
        curr->left = nullptr;
      }
      curr = curr->right;
    }
  }
};
// @leet end
