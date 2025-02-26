// @leet start
#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // Suppose we start at index i. If we reach to index j and the gas is not
    // enough. We should now decide the next start index s.
    // If i < s < j, then we can make sure that the car still can not reach to
    // index j + 1. Because at position i, The gas must be greater or equal than
    // the cost, let the 'more' be t (t >= 0). Even if with the extra t gas, we
    // cannot surpass j, then we absolutely cannot surpass j without it.
    int start_idx = 0;
    int total_surpass = 0;
    int surpass = 0;
    int n = gas.size();

    for (int i = 0; i < n; i++) {
      total_surpass += gas[i] - cost[i];
      surpass += gas[i] - cost[i];
      if (surpass < 0) {
        surpass = 0;
        start_idx = i + 1;
      }
    }

    return total_surpass >= 0 ? start_idx : -1;
  }
};
// @leet end
