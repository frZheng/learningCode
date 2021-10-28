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
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};

int main()
{

    
    int result;

    vector<vector<int> > intervals;
    Solution sl;
	result = sl.eraseOverlapIntervals(intervals);
    cout << "finish: " << result << endl;
    
    return 0;
};