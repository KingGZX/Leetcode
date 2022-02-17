/*
Q104
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

#include <iostream>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        // 可以用层序遍历
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            depth ++;
            int sz = que.size();
            for(int i = 0 ; i < sz ; i ++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        return depth;
    }

    // 用DFS的方式来计算每个结点的高度  此题中这种解法效率更高
    int maxDepth2(TreeNode* root){
        return Height(root);
    }

    int Height(TreeNode* root){
        if(!root) return 0;
        return max(Height(root->left), Height(root->right)) + 1;
    }
};

int main(){
    return 0;
}