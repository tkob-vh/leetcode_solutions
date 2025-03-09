// @leet start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (recursive(board, word, 0, i, j, m, n)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  bool recursive(vector<vector<char>> &board, const string word, int word_idx,
                 int i, int j, const int m, const int n) {
    if (word_idx == word.size()) {
      return true;
    }
    if (i < 0 || j < 0 || i == m || j == n) {
      return false;
    }
    if (board[i][j] != word[word_idx]) {
      return false;
    }

    char tmp = board[i][j];
    board[i][j] = 0;
    bool exists = recursive(board, word, word_idx + 1, i + 1, j, m, n) ||
                  recursive(board, word, word_idx + 1, i - 1, j, m, n) ||
                  recursive(board, word, word_idx + 1, i, j + 1, m, n) ||
                  recursive(board, word, word_idx + 1, i, j - 1, m, n);
    board[i][j] = tmp;

    return exists;
  }
};
// @leet end
