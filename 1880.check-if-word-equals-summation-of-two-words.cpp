#include <string>


// @leet start
class Solution {
public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        for(auto& it: firstWord) {
            it -= ('a' - '0');
        }
        for(auto& it: secondWord) {
            it -= ('a' - '0');
        }
        for(auto& it: targetWord) {
            it -= ('a' - '0');
        }

        int first = std::atoi(firstWord.c_str());
        int second = std::atoi(secondWord.c_str());
        int target = std::atoi(targetWord.c_str());

        return (first + second == target) ? true : false;
    }
};
// @leet end
