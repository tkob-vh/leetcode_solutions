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
class BSTIterator {
public:
  // Morris Travarsal
  BSTIterator(TreeNode *root) {
    TreeNode *curr = root;

    while (curr) {
      if (curr->left) {
        TreeNode *runner = curr->left;
        while (runner->right)
          runner = runner->right;
        runner->right = curr;
        TreeNode *tmp = curr;
        curr = curr->left;
        tmp->left = nullptr;
      } else {
        container.push_back(curr);
        curr = curr->right;
      }
    }

    size = container.size();
  }

  int next() { return container[idx++]->val; }

  bool hasNext() { return idx < size; }

private:
  std::vector<TreeNode *> container;
  int size;
  int idx = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @leet end
