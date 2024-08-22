#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return recursive_cal(price, special, needs, 0);
    }

private:
    int cost_;
    int recursive_cal(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs, int i) {
        // We are considering for special[i]

        // We have reached to the end of all special offers, and the remaining items
        // can't use special offers.
        if(i == special.size()) {
            return std::inner_product(price.cbegin(), price.cend(), needs.cbegin(), 0);
        }

        // We walk through the special offers from the end to the top.
        int result = recursive_cal(price, special, needs, i + 1);

        // needs -= special[i]
        std::transform(needs.begin(), needs.end(), special.at(i).cbegin(), needs.begin(), std::minus<int>());

        // If we can use this special offer
        if(std::all_of(needs.cbegin(), needs.cend(), [](int i){return i >= 0;})) {
            // Recursive invoke the function for the remaining items. We pass
            // i to the function because there's no limit on number of the same
            // special offers.
            result = min(result, special.at(i).back() + recursive_cal(price, special, needs, i));
        }
        // Restore the needs vector.
        std::transform(needs.begin(), needs.end(), special.at(i).cbegin(), needs.begin(), std::plus<int>());

        return result;
    }
};
// @leet end
