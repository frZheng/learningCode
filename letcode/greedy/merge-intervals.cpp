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
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            if (prices[i] >= minPrice && prices[i] <= minPrice + fee) {
                continue;
            }
            if (prices[i] > minPrice + fee) {
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        return result;
    }
};
int main()
{

    
    int result;
    vector<int> prices;
    int fee;
    Solution sl;
	result = sl.maxProfit(prices, fee);
    cout << "finish: " << endl;
    
    return 0;
};