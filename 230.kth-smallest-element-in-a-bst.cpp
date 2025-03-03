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
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int ans = 0;
    int idx = 0;
    inorder(root, k, idx, ans);
    return ans;
  }

private:
  void inorder(TreeNode *node, int k, int &idx, int &res) {
    if (node == nullptr) {
      return;
    }

    inorder(node->left, k, idx, res);

    idx++;
    if (idx == k) {
      res = node->val;
      return;
    }

    inorder(node->right, k, idx, res);
  }
};
// @leet end
