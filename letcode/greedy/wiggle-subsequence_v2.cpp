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
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result)
                result = count;
            if (count <= 0)
                count = 0;
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