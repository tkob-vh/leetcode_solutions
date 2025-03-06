// @leet start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> sons(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    vector<int> res(numCourses, 0);

    for (auto course_pair : prerequisites) {
      sons[course_pair[1]].push_back(course_pair[0]);
      indegree[course_pair[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    int count = numCourses;
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      res[numCourses - count] = course;
      count--;

      for (auto son : sons[course]) {
        if (--indegree[son] == 0) {
          q.push(son);
        }
      }
    }

    return count == 0 ? res : vector<int>();
  }
};
// @leet end
