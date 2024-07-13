#include <string>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::unordered_set;

// @leet start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int maxLength = 0;
      int len = s.length();
      unordered_set<char> charSet;
      int head = 0;

      for(int tail = 0; tail < len; tail++) {
        if(charSet.count(s[tail]) == 0) {
          charSet.insert(s[tail]);
          maxLength = std::max(maxLength, tail - head + 1);
        }
        else {
          while(charSet.count(s[tail])) {
            charSet.erase(s[head]);
            head++;
          }
          charSet.insert(s[tail]);
        }

      }
      return maxLength;
    }
};
// @leet end
