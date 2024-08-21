#include <string>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int strangePrinter(string s) {
        // Store the number of turns between the ith element and the jth element.
        // 0 <= i, j <= s.size()
        vector<vector<int>> lookup(s.size(), vector<int>(s.size()));       
        return dp(s, 0, s.size() - 1, lookup);

    }

private:
    // Use dynamic programming
    int dp(const string& s, int i, int j, vector<vector<int>>& lookup) {
        if(i > j) return 0;

        if(!lookup[i][j]) {
            // Initialize lookup[i][j].
            // If there is a s[k](i <= k <= j - 1), s[k] == s[j], then this
            // initial value is not the smallest. Else, it must be the smallest
            // and don't need to be updated more.
            lookup[i][j] = dp(s, i, j - 1, lookup) + 1;

            // Find the optimal partition.
            for(int k = i; k < j; k++) {
                if(s[k] == s[j]) {
                    // We don't need to consider about s[j] because s[k] == s[j]
                    lookup[i][j] = min(lookup[i][j], dp(s, i, k, lookup) + dp(s, k + 1, j - 1, lookup));
                }
            }
        }

        return lookup[i][j];

    }
};
// @leet end
