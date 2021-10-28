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
private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path += to_string(cur->val);
        if (cur->left = NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left)
            traversal(cur->left, path, result);
        if (cur->right)
            traversal(cur->right, path, result);
    }
public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> result;
            vector<int> path;
            if (root == NULL) {
                return result;
            }
            traversal(root, path, result);
            return result;
        }
};
