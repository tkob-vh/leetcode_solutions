// @leet start
#include <vector>
using std::vector;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1; // The position current of processing element (from the
                       // end to the beginning).

    while (j >= 0) {
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
  }
};
// @leet end
