// @leet start
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> entry;
    backtrack(result, entry, candidates, 0, target, 0);
    return result;
  }

private:
  void backtrack(vector<vector<int>> &result, vector<int> &entry,
                 const vector<int> &candidates, int sum, const int target,
                 int start) {
    if (sum == target) {
      result.push_back(entry);
      return;
    } else if (sum > target) {
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      entry.push_back(candidates[i]);
      backtrack(result, entry, candidates, sum + candidates[i], target, i);
      entry.pop_back();
    }
  }
};
// @leet end
