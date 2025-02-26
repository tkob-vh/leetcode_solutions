// @leet start
#include <algorithm>
#include <execution>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::sort(std::execution::par, nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> res;
    if (nums[0] > 0) {
      return res;
    }
    if (len == 3) {
      int sum = std::reduce(std::execution::par, nums.cbegin(), nums.cend(), 0);
      if (sum == 0) {
        res.emplace_back(nums);
        return res;
      } else {
        return res;
      }
    }

    for (int i = 0; i < len; i++) {
      if (nums[i] > 0)
        break;

      // Skip the redundant elements.
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int low = i + 1, high = len - 1;
      while (low < high) {
        int sum = nums[i] + nums[low] + nums[high];
        if (sum > 0) {
          high--;
        } else if (sum < 0) {
          low++;
        } else {
          res.emplace_back(vector{nums[i], nums[low], nums[high]});
          int tmp_low = nums[low], tmp_high = nums[high];

          // Skip the redundant elements.
          while (low < high && tmp_low == nums[low]) {
            low++;
          }
          while (low < high && tmp_high == nums[high]) {
            high--;
          }
        }
      }
    }

    return res;
  }
};
// @leet end
