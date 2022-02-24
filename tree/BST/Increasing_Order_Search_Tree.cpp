/*
Q897
给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，
并且每个节点没有左子节点，只有一个右子节点。

示例 1：
输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

示例 2：
输入：root = [5,1,7]
输出：[1,null,5,null,7]
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

    TreeNode* increasingBST(TreeNode* root) {
        // 用到前面非递归形式的先序遍历
        if(!root) return nullptr;
        TreeNode* p, *q;
        p = new TreeNode(-1);
        q = p;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            TreeNode* temp = st.top();
            temp->left = nullptr;
            st.pop();
            q->right = temp;
            q = q->right;
            root = temp->right;
        }
        return p->right;
    }

    /*
    // 会浪费较多的空间
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<TreeNode*> vec;
        Preorder(vec, root);
        TreeNode* temp = new TreeNode(vec[0]->val);
        TreeNode* q = temp;
        for(int i = 1 ; i < vec.size() ; i ++){
            TreeNode* p = new TreeNode(vec[i]->val);
            q->right = p;
            q = p;
        }
        return temp;
    }

    void Preorder(vector<TreeNode*>& vec, TreeNode* root){
        if(root){
            Preorder(vec, root->left);
            vec.push_back(root);
            Preorder(vec, root->right);
        }
    }
    */

};

int main(int argc, const char** argv) {
    return 0;
}