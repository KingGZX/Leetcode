/*
Q404
给定二叉树的根节点 root ，返回所有左叶子之和。

示例 1：
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

示例 2:
输入: root = [1]
输出: 0
*/

#include <iostream>
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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left){
            if(!root->left->left && !root->left->right)
                ans += root->left->val;
            else
                sumOfLeftLeaves(root->left);
        }
        if(root->right)
            sumOfLeftLeaves(root->right);
        return ans;
    }
};

int main(){
    return 0;
}