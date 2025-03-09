// @leet start
#include <array>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> result;
    result.push_back("");

    for (auto digit : digits) {
      vector<string> tmp;
      for (auto c : letters[digit - '0']) {
        for (auto r : result) {
          tmp.push_back(r + c);
        }
      }
      std::swap(tmp, result);
    }
    return result;
  }

private:
  const array<string, 10> letters{"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @leet end
