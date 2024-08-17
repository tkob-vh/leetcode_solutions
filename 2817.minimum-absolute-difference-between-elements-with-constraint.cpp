// @leet start
#include <climits>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int answer = INT_MAX;
        multiset<int> set_;

        int length = nums.size();

        // iterate from the x element.
        for(int i = x; i < length; i++) {
            // In each iteration, insert the x-ahead element into the set.
            // Evaluate the relation between the current element and elements
            // in the set (which all meet the constraint). We don't consider the
            // elements after nums[i] (such as j) in iteration i, because it's
            // our work in iteration j.
            set_.insert(nums[i - x]);

            auto it = set_.lower_bound(nums[i]);

            if(it != set_.end()) {
                answer = min(answer, *it - nums[i]);
            }
            if(it != set_.begin()) {
                it--;
                answer = min(answer, nums[i] - *it);
            }
        }
        return answer;
    }
};
// @leet end
