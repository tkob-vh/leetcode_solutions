// @leet start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // The sons of the ith course (outdegree).
    vector<vector<int>> sons(numCourses, vector<int>());

    // The number of fathers of the ith course (indegree num).
    vector<int> indegree_num(numCourses, 0);

    for (auto course_pair : prerequisites) {
      sons[course_pair[1]].push_back(course_pair[0]);
      indegree_num[course_pair[0]]++;
    }

    queue<int> q;

    // Initialize the queue with all courses whose indegree is zero.
    for (int i = 0; i < numCourses; i++) {
      if (indegree_num[i] == 0)
        q.push(i);
    }

    if (q.empty())
      return false;

    while (!q.empty()) {
      int course = q.front();
      q.pop();
      // Remove the course
      numCourses--;

      // indegree - 1 for its sons accordingly.
      for (auto son : sons[course]) {
        if (--indegree_num[son] == 0)
          q.push(son);
      }
    }

    return numCourses == 0;
  }
};
// @leet end
