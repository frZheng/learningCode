#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;


struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL)
            return 0;

        int leftDepth = getDepth(node->left);
        if (leftDepth == -1)
            return -1;
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1) {
            return -1;
        }
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
};

int main()
{

    TreeNode* root = new TreeNode(1);
    bool result;
    // root->val = 1;
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sl;
	result = sl.isBalanced(root);
    cout << result << endl;
    
    return 0;
};