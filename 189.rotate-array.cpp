// @leet start
#include <ctime>
#include <vector>
using std::vector;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> tmp(size, 0);
    for (int i = 0; i < size; i++) {
      tmp[(i + k) % size] = nums[i];
    }
    nums.swap(tmp);
  }
};
// @leet end
