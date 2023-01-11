/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-11 11:55:31
 * @LastEditTime: 2023-01-11 12:30:44
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/reconstruct_binary_tree.cpp
 * @Description: Please implement
 */

/*
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

示例 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int& ptr){
        // we need to judge whether the current element we traverse in the interval of [left, right] of inorder vector
        if(ptr >= preorder.size() || right < left) return nullptr;
        auto iter = find(inorder.begin() + left, inorder.begin() + right + 1, preorder[ptr]);
        if(iter != inorder.begin() + right + 1){
            int index = distance(inorder.begin(), iter);
            TreeNode* node = new TreeNode(preorder[ptr ++]);
            node->left = helper(preorder, inorder, left, index - 1, ptr);
            node->right = helper(preorder, inorder, index + 1, right, ptr);
            return node;
        }
        else return nullptr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return nullptr;
        int preptr = 0;
        TreeNode* root = new TreeNode(preorder[preptr]);
        int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[preptr ++]));
        root->left = helper(preorder, inorder, 0, index - 1, preptr);
        root->right = helper(preorder, inorder, index + 1, preorder.size() - 1, preptr);
        return root;
    }
};

int main(){
    Solution s;
    vector<int> pre{3, 9, 20, 15, 7};
    vector<int> in{9, 3, 15, 20, 7};
    s.buildTree(pre, in);
    return 0;
}