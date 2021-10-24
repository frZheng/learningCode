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

// class Solution {
// private:
//     int getDepth(TreeNode* root) {
//         stack<TreeNode *> st;
//         if (root != NULL)
//             st.push(root);
//         int depth = 0;
//         int result = 0;
//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             if (node != NULL) {
//                 st.pop();
//                 st.push(node);
//                 st.push(NULL);
//                 depth++;
//                 if (node->right)
//                     st.push(node->right);
//                 if (node->left)
//                     st.push(node->left);
//             } else {
//                 st.pop();
//                 node = st.top();
//                 st.pop();
//                 depth--;
//             }
//             // result = result > depth ? result : depth;
//             result = max(result, depth);
//         }
//         return result;
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         stack<TreeNode *> st;
//         if (root == NULL)
//             return true;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();
//             if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
//                 return false;
//             }
//             if (node->right)
//                 st.push(node->right);
//             if (node->left)
//                 st.push(node->left);
            
//         }
//         return true;
//     }
// };

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            queue<TreeNode *> que;
            if (root != NULL)
                que.push(root);
            int minDepth = 0;
            int depth = 0;
            while(!que.empty()) {
                int size = que.size();
                depth++;
                for (int i = 0; i < size; i++) {
                    TreeNode *node = que.front();
                    que.pop();
                    if (node->left)
                        que.push(node->left);
                    else if(minDepth == 0){
                        minDepth = depth;
                    }
                    if (node->right)
                        que.push(node->right);
                    else if(minDepth == 0){
                        minDepth = depth;
                        
                    }
                    if (minDepth != 0 && depth > minDepth + 1)
                        cout << "minDepth " << minDepth << endl;
                        return false;
                }
            }
            return true;
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