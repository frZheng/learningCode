#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
private:
    int result;
    int traversal(TreeNode *cur) {
        if (cur == NULL)
            return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if (left == 2 && right == 2)
            return 0;
        else if (left == 0 && right == 0) {
            result++;
            return 1;
        } else
            return 2;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};
