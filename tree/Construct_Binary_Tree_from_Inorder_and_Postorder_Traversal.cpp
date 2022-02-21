/*
Q106
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， 
postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]

示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]
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
    // 中序遍历是 左->根->右
    // 后序遍历是 左->右->根
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ptr = postorder.size() - 1;     // 从主根开始
        TreeNode* root = createNode(inorder, postorder, ptr, 0, inorder.size());
        return root;
    }
    // lb means lower bound, ub means upper bound
    TreeNode* createNode(vector<int>& in, vector<int>& p, int& ptr, int lb, int ub){
        if(lb >= in.size()) return nullptr;
        int cur = -1;
        TreeNode* root;
        for(int i = lb ; i < ub && i < in.size() ; i ++){
            if(in[i] == p[ptr]){
                root = new TreeNode(p[ptr]);
                cur = i;
                ptr --;
                break;
            }
        }
        if(cur == -1) return nullptr;
        root->right = createNode(in, p, ptr, cur + 1, ub);
        root->left = createNode(in, p, ptr, lb, cur);
        return root;
    }
};

int main(){
    return 0;
}