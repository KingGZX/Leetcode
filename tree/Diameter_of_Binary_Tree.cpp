/*
Q543
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
这条路径可能穿过也可能不穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 

注意：两结点之间的路径长度是以它们之间边的数目表示。
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
    int diameterOfBinaryTree(TreeNode* root) {
        // 思路仍旧是 用辅助函数Height计算经过某一节点的最长路径(即左子树深度+右子树深度+1)
        int ans = 0;
        Height(root, ans);
        return ans;
    }
    // 函数过程中我们去更新ans值，但此函数返回的本身应该是以某结点为根的树的深度
    int Height(TreeNode* root, int& ans){
        if(!root) return 0;
        int leftHeight = Height(root->left, ans);
        int rightHeight = Height(root->right, ans);
        ans = max(ans, leftHeight + rightHeight + 1);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main(){
    return 0;
}