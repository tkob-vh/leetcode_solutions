// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int i = 0; // The current processing element.
    int j = 0; // The place to store the nums[i]

    while (i < nums.size()) {
      if (nums[i] == val) {
        i++;
      } else {
        nums[j++] = nums[i++];
      }
    }

    return j;
  }
};
// @leet end
