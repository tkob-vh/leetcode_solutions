// @leet start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int ans = 0;
    int cur_far = 0;
    int cur_end = 0;
    int size = nums.size();

    // This is an implicit bfs solution. `i == cur_end` means you visited all
    // the items on the current level. Incrementing `ans++` is like incrementing
    // the level you are on. And `cur_end = cur_far` is like getting the queue
    // size (level size) for the next level you are traversing.
    for (int i = 0; i < size - 1; i++) {
      cur_far = max(cur_far, i + nums[i]);

      if (i == cur_end) {
        ans++;
        cur_end = cur_far;

        if (cur_end >= size - 1) {
          break;
        }
      }
    }

    return ans;
  }
};
// @leet end
