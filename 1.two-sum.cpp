#include <vector>
#include <unordered_map>

using std::vector;

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // Time Complexity: O(n)
      // Space Complexity: O(n)
      // Use hashtable
      std::unordered_map<int, int> numMap;
      for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(numMap.count(complement)) {
          return {i, numMap[complement]};
        }
        numMap[nums[i]] = i;
      }
      return {};
    }
};
// @leet end
