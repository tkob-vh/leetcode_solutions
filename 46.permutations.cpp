// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> entry{};
    backtrack(result, entry, nums);

    return result;
  }

private:
  void backtrack(vector<vector<int>> &result, vector<int> &entry,
                 const vector<int> &nums) {
    if (entry.size() == nums.size()) {
      result.push_back(entry);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (find(entry.begin(), entry.end(), nums[i]) != entry.end()) {
        continue;
      }

      entry.push_back(nums[i]);
      backtrack(result, entry, nums);
      entry.pop_back();
    }
  }
};
// @leet end
