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
        vector<string> binaryTreePaths(TreeNode* root) {
            stack<TreeNode *> treest;
            stack<string> pathst;
            vector<string> result;
            if (root == NULL)
                return result;
            treest.push(root);
            pathst.push(to_string(root->val));
            while (!treest.empty()) {
                TreeNode *node = treest.top();
                treest.pop();
                string path = pathst.top();
                pathst.pop();
                if (node->left == NULL && node->right == NULL) {
                    result.push_back(path);
                }
                if (node->right) {
                    treest.push(node->right);
                    pathst.push(path + "->" + to_string(node->right->val))
                }
                if (node->left) {
                    treest.push(node->left);
                    treest.push(path + "->" + to_string(node->left->val));
                }
                return result;
            }
        }
};
