#include <string.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            queue<TreeNode *> que;
            if (root != NULL)
                que.push(root);
            vector<int> result;
            while (!que.empty()) {
                int size = que.size();
                int maxValue = INT_MIN;
                for (int i = 0; i < size; i++) {
                    TreeNode *node = que.front();
                    que.pop();
                    maxValue = node->val > maxValue ? node->val : maxValue;
                    if (node->left)
                        que.push(node->left);
                    if (node->right)
                        que.push(node->right);
                }
                result.push_back(maxValue);
            }
            return result;
        }
};



int main()
{

    TreeNode* root = new TreeNode(1);
    vector<int> result;
    // root->val = 1;
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sl;
	result = sl.largestValues(root);
    for (unsigned int i = 0; i < result.size(); i++)
    {
        cout << "输出字符串:\t" << result[i] << endl;
    }

    return 0;
}