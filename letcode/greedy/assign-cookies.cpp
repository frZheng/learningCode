#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};

// 存在错误
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         if (s.size() == 0) return 0
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         int index = 0;
//         for (int i = 0; i <= s.size(); i++) {
//             if (index < g.size() && s[index] >= g[i]) {
//                 index++;
//             }
//         }
//         return index;
//     }
// };
int main()
{

    
    int result;

    vector<int> g;
    vector<int> s;
    Solution sl;
	result = sl.findContentChildren(g, s);
    cout << "finish: " << result << endl;
    
    return 0;
};