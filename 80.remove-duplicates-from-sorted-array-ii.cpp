// @leet start
#include <vector>
using std::vector;
class Solution {

#define N 2

public:
  int removeDuplicates(vector<int> &nums) {
    int index = N; // The place to store the current processing element.

    for (int i = N; i < nums.size(); i++) {
      if (nums[i] > nums[index - N]) {
        nums[index++] = nums[i];
      }
    }

    return std::min(index, (int)nums.size());
  }
};
// @leet end
