// @leet start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int hIndex(vector<int> &citations) {
    // Another method can use a bucket, but without sorting, it is not
    // cache-friendly.

    sort(citations.begin(), citations.end());
    int n = citations.size();

    // Total n papers. If the paper at index i has p citations, then (n - i)
    // papers have at least p citations. We need (n - i) >= p. That is, if (n -
    // i) >= p, we can continue to iterate.
    for (int i = 0; i < n; i++) {
      if ((n - i) <= citations[i]) {
        return n - i;
      }
    }
    return 0;
  }
};
// @leet end
