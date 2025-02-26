// @leet start
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 1);

    // Prefix product
    int curr = 1;
    for (int i = 0; i < nums.size(); i++) {
      res[i] *= curr;
      curr *= nums[i];
    }

    // Suffix product
    curr = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] *= curr;
      curr *= nums[i];
    }

    return res;
  }
};
// @leet end
