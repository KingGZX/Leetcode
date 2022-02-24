/*
Q94
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[2,1]

示例 5：
输入：root = [1,null,2]
输出：[1,2]
*/

#include <iostream>
#include <vector>
#include <stack>
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
    // 中序遍历就是要求我们按照 左->根->右 顺序输出
    // 要求我们用非递归的方式实现
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){    // 通过这一步把以root为根的向左深度递归下去的结点全部压栈
                st.push(root);
                root = root->left;
            }
            TreeNode* temp = st.top();  // 弹出了最左结点
            st.pop();
            ans.push_back(temp->val);
            root = temp->right; // 访问右子树
        }
        return ans;
    }
};

int main(){
    return 0;
}