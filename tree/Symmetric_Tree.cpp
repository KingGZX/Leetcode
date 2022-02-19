/*
Q101
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
*/


#include <iostream>
#include <deque>
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
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    以此对称树为例，我们实际上递归地去判断两棵子树是否相等。
    所以对于左右子树两 根节点而言，有四种情况：
        两者都为空
        两者其中一个为空
        两者均不为空，但两个根结点值不相等
        两者均不为空，且两个根结点值相等。因此递归判断左右子树，这里注意一一对应：
            即我们现在实际上去判断第三层，所以应该是 left->left 和 right->right比较，left->right 和 right->left比较
    */
    bool isSymmetric(TreeNode* root) {
        return Symmetric(root->left, root->right);
    }
    
    bool Symmetric(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        if(left->val != right->val){
            return false;
        }
        return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
    }
};

int main(){
    return 0;
}