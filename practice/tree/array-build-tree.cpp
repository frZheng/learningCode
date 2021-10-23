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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
 
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
 
        // 总是选择中间位置左边的数字作为根节点
        int mid = (left + right)>>1;
        //新生成一个节点，节点的值为中间的数值
        TreeNode* root = new TreeNode(nums[mid]);
        //生成左子树
        root->left = helper(nums, left, mid - 1);
        //生成右子树
        root->right = helper(nums, mid + 1, right);
        return root;
    }
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

    vector<int> array = { 3, 9, 20, 2, 5, 15, 7};
    string v1 = {3, 9, 20, null, null, 15, 7};
    vector<int> result;
    Solution sl;
	TreeNode* root = sl.sortedArrayToBST(array);

    sl.inOrderTraversal(root,result);
    for (unsigned int i = 0; i < result.size(); i++)
    {
        cout << "输出字符串:\t" << result[i] << endl;
    }
    return 0;
};