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
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result)
                result = dp[i];
        }
        return result;
    }
};

int main()
{

    
    int result;

    vector<int> g;
    Solution sl;
	result = sl.maxSubArray(g);
    cout << "finish: " << result << endl;
    
    return 0;
};