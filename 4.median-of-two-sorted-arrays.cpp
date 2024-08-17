#include <cassert>
#include <climits>
#include <vector>

using std::vector;

// @leet start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 > len2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int start1 = 0;
        int end1 = len1;
        int total_len = len1 + len2;
        int half_len = (total_len + 1) / 2;

        while (start1 <= end1) {
            int mid1 = (start1 + end1) / 2;
            int mid2 = half_len - mid1;

            int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int right1 = (mid1 == len1) ? INT_MAX : nums1[mid1];
            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int right2 = (mid2 == len2) ? INT_MAX : nums2[mid2];

            if (left1 <= right2 && left2 <= right1) {
                if (total_len % 2 == 1) {
                    return std::max(left1, left2);
                } else {
                    return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                end1 = mid1 - 1;
            } else {
                start1 = mid1 + 1;
            }
        }
        return 0;
    }
};

// @leet end
