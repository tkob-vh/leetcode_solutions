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
#include <limits>
class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    if (root->left != nullptr) {
      getMinimumDifference(root->left);
    }

    if (prev != nullptr) {
      m_min = std::min(m_min, root->val - prev->val);
    }

    prev = root;

    if (root->right != nullptr) {
      m_min = std::min(m_min, getMinimumDifference(root->right));
    }

    return m_min;
  }

private:
  int m_min = std::numeric_limits<int>::max();
  TreeNode *prev = nullptr;
};
// @leet end
