// @leet start
#include <vector>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int m = board.size(), n = board[0].size();
    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O') {
        dfs(board, 0, j);
      }
      if (board[m - 1][j] == 'O') {
        dfs(board, m - 1, j);
      }
    }

    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') {
        dfs(board, i, 0);
      }
      if (board[i][n - 1] == 'O') {
        dfs(board, i, n - 1);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '#') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

private:
  // Used to mark the boundry 'O's (including their adjacent 'O's).
  void dfs(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != 'O') {
      return;
    }
    board[i][j] = '#';
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
  }
};
// @leet end
