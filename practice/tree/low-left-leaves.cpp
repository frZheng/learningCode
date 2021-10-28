#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;


struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
    public:
        int maxLen = INT_MIN;
        int maxleftValue;
        void traversal(TreeNode* root, int leftLen) {
            if (root->left == NULL && root->right == NULL) {
                if (leftLen > maxLen) {
                    maxLen = leftLen;
                    maxleftValue = root->val;
                }
                return;
            }
            if (root->left) {
                leftLen++;
                traversal(root->left, leftLen);
                leftLen--;
            }
            if (root->right) {
                leftLen++;
                traversal(root->right, leftLen);
                leftLen--;
            }
            return;
        }
        int finrBottomLeftValue(TreeNode* root) {
            traversal(root, 0);
            return maxleftValue;
        }
};



int main()
{

    TreeNode* root = new TreeNode(1);
    int result;
    // root->val = 1;
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sl;
	result = sl.finrBottomLeftValue(root);

    cout << "输出字符串:\t" << result << endl;


    return 0;
};