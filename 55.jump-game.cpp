// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int total_steps = nums.size() - 1;
    if (total_steps == 0)
      return true;

    int min_step = 1;

    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] >= min_step) {
        min_step = 1;
        continue;
      } else {
        min_step++;
      }
    }
    if (min_step == 1)
      return true;
    else
      return false;
  }
};
// @leet end
