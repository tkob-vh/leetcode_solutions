#include <string>
#include <vector>

using namespace std;

// @leet start
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // Iterate through the string
        for(int i = 0; i < s.length(); i++) {

            
            while(indices.at(i) != i) {
                swap(s.at(i), s.at(indices.at(i)));
                swap(indices.at(i), indices.at(indices.at(i)));
            }
        }        
        return s;
    }
};
// @leet end
