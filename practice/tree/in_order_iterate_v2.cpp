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
        vector<int> inOrderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> st;
            if(root != NULL)
                st.push(root);
            while(!st.empty()) {
                TreeNode* node = st.top();
                if (node != NULL) {
                    st.pop();
                    if (node->right)
                        st.push(node->right);
                    st.push(node);
                    st.push(NULL);
                    if (node->left)
                        st.push(node->left);
                } else {
                    st.pop();
                    node = st.top();
                    st.pop();
                    result.push_back(node->val);
                }
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
	result = sl.inOrderTraversal(root);
    for (unsigned int i = 0; i < result.size(); i++)
    {
        cout << "输出字符串:\t" << result[i] << endl;
    }

    return 0;
}