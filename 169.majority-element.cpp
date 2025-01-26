// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int res;
    int count = 0;

    for (auto n : nums) {
      if (count == 0) {
        res = n;
        count++;
        continue;
      }
      if (res == n) {
        count++;
      } else {
        count--;
      }
    }
    return res;
  }
};
// @leet end
