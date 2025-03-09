// @leet start
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> tmp;
    backtrack(result, tmp, 1, n, k);

    return result;
  }

private:
  void backtrack(vector<vector<int>> &result, vector<int> &entry, int start_idx,
                 int n, int k) {
    if (k == 0) {
      result.push_back(entry);
      return;
    }

    for (int i = start_idx; i <= n; i++) {
      entry.push_back(i);
      backtrack(result, entry, i + 1, n, k - 1);
      entry.pop_back();
    }
  }
};
// @leet end
