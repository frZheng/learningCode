#include <string.h>
#include <vector>
#include <iostream>
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
        vector<vector<int> > levelOrder(TreeNode* root) {
            queue<TreeNode *> que;
            vector<vector<int> > result;
            if (root != NULL)
                que.push(root);
            while(!que.empty()) {
                int size = que.size();
                vector<int> vec;
                for (int i = 0; i < size; i++) {
                    TreeNode *node = que.front();
                    que.pop();
                    vec.push_back(node->val);
                    if (node->left)
                        que.push(node->left);
                    if (node->right)
                        que.push(node->right);
                }
                result.push_back(vec);
            }
            return result;
        }
};



void reverse_with_iterator(vector<vector<int> > vec)
{
    if (vec.empty())
    {
        cout << "The vector is empty!" << endl;
        return;
    }
 
    vector<int>::iterator it;
    vector<vector<int> >::iterator iter;
    vector<int> vec_tmp;
 
    cout << "Use iterator : " << endl;
    for(iter = vec.begin(); iter != vec.end(); iter++)
    {
        vec_tmp = *iter;
        for(it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

int main()
{

    TreeNode* root = new TreeNode(1);
    vector<vector<int> > result;
    // root->val = 1;
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sl;
	result = sl.levelOrder(root);

    reverse_with_iterator(result);
    return 0;
    
}