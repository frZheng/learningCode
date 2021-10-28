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
        int finrBottomLeftValue(TreeNode* root) {
            queue<TreeNode *> que;
            if (root != NULL)
                que.push(root);
            int result = 0;
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0)
                    result = node->value;
                if (node->left)
                    que.push(root->left);
                if (node->right)
                    que.push(root->right);
            }
        }
        return result;
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