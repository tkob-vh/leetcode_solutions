// @leet start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string tmp;
    recursive(result, tmp, 0, 0, n);
    return result;
  }

private:
  void recursive(vector<string> &result, string entry, int left, int right,
                 const int n) {
    if (entry.size() == 2 * n) {
      result.push_back(entry);
      return;
    }

    if (left < n) {
      recursive(result, entry + "(", left + 1, right, n);
    }
    if (right < left) {
      recursive(result, entry + ")", left, right + 1, n);
    }
  }
};
// @leet end
