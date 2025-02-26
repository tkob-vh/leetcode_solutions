// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdlib>

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // The stop condition.
    // If we reach the leaf, or find the targets(p and q), return it.
    if (root == NULL || root->val == p->val || root->val == q->val) {
      return root;
    }
    // Traverse the left subtree.
    TreeNode *left = lowestCommonAncestor(root->left, p, q);

    // Traverse the right subtree.
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    return !left ? right : (!right ? left : root);
  }
};
// @leet end
