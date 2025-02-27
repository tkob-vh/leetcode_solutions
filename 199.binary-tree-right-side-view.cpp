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
using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    traverse(root, res, 1);
    return res;
  }

private:
  void traverse(TreeNode *node, vector<int> &res, int depth) {
    if (node == nullptr) {
      return;
    }
    if (res.size() < depth) {
      res.push_back(node->val);
    }

    traverse(node->right, res, depth + 1);
    traverse(node->left, res, depth + 1);
  }
};
// @leet end
