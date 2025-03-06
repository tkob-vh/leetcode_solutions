// @leet start
#include <algorithm>
#include <cmath>
#include <execution>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    int n2 = n * n;
    int label = 1;

    vector<pair<int, int>> cells(n2 + 1);
    vector<int> columns(n);

    iota(columns.begin(), columns.end(), 0);

    for (int row = n - 1; row >= 0; row--) {
      for (int column : columns) {
        cells[label++] = pair(row, column);
      }
      reverse(std::execution::par, columns.begin(), columns.end());
    }

    vector<int> dist(n2 + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (int next = curr + 1; next <= min(curr + 6, n2); next++) {
        auto [i, j] = cells[next];
        int dest = board[i][j] == -1 ? next : board[i][j];
        if (dist[dest] == -1) {
          dist[dest] = dist[curr] + 1;
          q.push(dest);
        }
      }
    }

    return dist[n2];
  }
};
// @leet end
