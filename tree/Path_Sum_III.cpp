/*
Q437
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 

示例 1：
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。

示例 2：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
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
    int sum = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            int tempSum = 0;
            findPath(root, targetSum, tempSum);
            if(root->left){
                pathSum(root->left, targetSum);
            }
            if(root->right){
                pathSum(root->right, targetSum);
            }
        }
        return sum;
    }

    void findPath(TreeNode* root, int targetSum, int tempSum){
        if(root){
            tempSum += root->val;
            if(tempSum == targetSum){
                sum ++;
            }
            if(root->left){
                findPath(root->left, targetSum, tempSum);
            }
            if(root->right){
                findPath(root->right, targetSum, tempSum);
            }
        }
    }
};

int main(){
    return 0;
}