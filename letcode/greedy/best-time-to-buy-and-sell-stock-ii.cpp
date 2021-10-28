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
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++)
            result += max(prices[i] - prices[i - 1], 0);
        return result;
    }
};

int main()
{

    
    int result;

    vector<int> g;
    Solution sl;
	result = sl.maxProfit(g);
    cout << "finish: " << result << endl;
    
    return 0;
};