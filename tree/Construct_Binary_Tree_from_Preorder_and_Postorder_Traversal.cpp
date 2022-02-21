/*
Q889
给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，
postorder 是同一棵树的后序遍历，重构并返回二叉树。
如果存在多个答案，您可以返回其中 任何 一个。
示例 1：
输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]

示例 2:
输入: preorder = [1], postorder = [1]
输出: [1]
*/

#include <iostream>
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
    // 先序遍历是 根->左->右
    // 后序遍历是 左->右->根
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
    }
};