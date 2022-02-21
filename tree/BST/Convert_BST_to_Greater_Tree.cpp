/*
Q1038
给定一个二叉搜索树 root (BST)，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。

提醒一下， 二叉搜索树 满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。

示例 1：
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

示例 2：
输入：root = [0,null,1]
输出：[1,null,1]
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
    // 采用 后序遍历 可以将树的值从大到小输出，然后累加起来即可
    int temp = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root){
            // 这样一来 temp就一直保持着从大到小的一个累加和
            bstToGst(root->right);
            root->val += temp;
            temp = root->val;
            bstToGst(root->left);
        }
        return root;
    }

    // void postOrder(TreeNode)
};

int main(){
    return 0;
}