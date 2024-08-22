
// @leet start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long long ans = 0;
#pragma unroll
        for(int i = 0; i * cost1 <= total; i++) {
            ans += (total - i * cost1) / cost2 + 1;
        }
        return ans;
    }
};
// @leet end
