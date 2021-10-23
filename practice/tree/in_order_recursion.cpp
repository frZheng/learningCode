#include <string.h>
#include <vector>
#include <iostream>

using namespace std;


struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
    public:
        void inOrderTraversal(TreeNode* root, vector<int>& vec) {
            if (root == NULL)
                return;
            inOrderTraversal(root->left,vec);
            vec.push_back(root->val);
            inOrderTraversal(root->right,vec);
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
	sl.inOrderTraversal(root,result);
    for (unsigned int i = 0; i < result.size(); i++)
    {
        cout << "输出字符串:\t" << result[i] << endl;
    }

    return 0;
}