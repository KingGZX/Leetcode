/*
Q110
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true

示例 2：
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false

示例 3：
输入：root = []
输出：true
*/




#include <iostream>
#include <math.h>
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
    // 二叉平衡树的概念就是结点的左右子树最大高度差不大于1
    bool isBalanced(TreeNode* root) {
        if(maxHeight(root) == -1)
            return false;
        return true;
    }

    // 辅助函数maxHeight计算以结点root为根的树高，返回值为-1时说明不平衡，即只要有不平衡产生就一路返回-1直接退出
    int maxHeight(TreeNode* root){
        if(!root) return 0;
        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};

int main(){
    return 0;
}