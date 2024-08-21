#include <vector>
#include <unordered_set>


// @leet start
class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.cbegin(), nums1.cend());
        std::unordered_set<int> set2(nums2.cbegin(), nums2.cend());

        std::vector<int> list1{};
        std::vector<int> list2{};

        for(auto ele: set1) {
            if(set2.count(ele) == 0) {
                list1.push_back(ele);
            } 
        }

        for(auto ele: set2) {
            if(set1.count(ele) == 0) {
                list2.push_back(ele);
            }
        }

        return {list1, list2}; 
    }
};
// @leet end
