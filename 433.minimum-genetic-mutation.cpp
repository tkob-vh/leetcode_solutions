// @leet start
#include <ctime>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    unordered_set<string> bankset{bank.begin(), bank.end()};
    if (!bankset.contains(endGene)) {
      return -1;
    }

    int step = 0;
    queue<string> q;
    q.push(startGene);

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        string curr = q.front();
        q.pop();

        if (curr == endGene) {
          return step;
        }

        bankset.erase(curr);

        for (int i = 0; i < 8; i++) {
          string tmp = curr;
          tmp[i] = 'A';
          if (bankset.contains(tmp))
            q.push(tmp);
          tmp[i] = 'T';
          if (bankset.contains(tmp))
            q.push(tmp);
          tmp[i] = 'C';
          if (bankset.contains(tmp))
            q.push(tmp);
          tmp[i] = 'G';
          if (bankset.contains(tmp))
            q.push(tmp);
        }
      }
      step++;
    }
    return -1;
  }
};
// @leet end
