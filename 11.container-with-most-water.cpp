// @leet start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max_v = 0;

    for (int i = 0, j = height.size() - 1; i < j;) {
      int v = (j - i) * std::min(height[i], height[j]);
      max_v = std::max(max_v, v);

      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }

    return max_v;
  }
};
// @leet end
