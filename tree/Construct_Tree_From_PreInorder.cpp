/*
Q105
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]

示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]
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
    // 中序遍历是 左->根->右
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cur_ptr = 0;
        TreeNode* root = createNode(preorder, inorder, cur_ptr, 0, inorder.size());
        return root;
    }
    // refers to 'lower bound' and 'upper bound' in vector inorder
    TreeNode* createNode(vector<int>& p, vector<int>& in, int& cur_p, int lb, int ub){  
        TreeNode* root = nullptr;
        // 去给定界限里找当前结点，然后划定新的界限建树
        int cur_in = -1; 
        for(int i = lb ; i < ub && i < in.size() ; i ++){
            if(p[cur_p] == in[i]){
                cur_in = i;
                root = new TreeNode(p[cur_p]);
                cur_p ++;
                break;
            }
        }
        if(cur_in == -1)
            return nullptr;
        root->left = createNode(p, in, cur_p, 0, cur_in);
        root->right = createNode(p, in, cur_p, cur_in + 1, ub);
        return root;
    }
};

int main(){
    vector<int> vec1{1, 2};
    vector<int> vec2{1, 2};
    Solution s;
    s.buildTree(vec1, vec2);
    return 0;
}