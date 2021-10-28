#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

// 存在问题
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if (nums.size() == 1)
//             return 0;
//         int curDistance = 0;
//         int ans = 0;
//         int nextDistance = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             nextDistance = max(nums[i] + 1, nextDistance);
//             if (i == curDistance) {
//                 ans++;
//                 curDistance = nextDistance;
//                 if (nextDistance >= nums.size() - 1)
//                     break;
//             } else
//                 break;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int curDistance = 0;
        int ans = 0;
        int nextDistance = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance) {
                curDistance = nextDistance;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{

    
    int result;

    vector<int> g;
    Solution sl;
	result = sl.jump(g);
    cout << "finish: " << result << endl;
    
    return 0;
};