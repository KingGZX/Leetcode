/*
Q655
给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
矩阵的列数 n 应该等于 2height+1 - 1 。
根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
继续这一过程，直到树中的所有节点都妥善放置。
任意空单元格都应该包含空字符串 "" 。
返回构造得到的矩阵 res 。

 

示例 1：


输入：root = [1,2]
输出：
[["","1",""],
 ["2","",""]]
示例 2：


输入：root = [1,2,3,null,4]
输出：
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
*/




#include <iostream>
#include <vector>
#include <queue>
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
    int height = 0;
    void calcheight(TreeNode* root, int h){
        if(root){
            if(root->left)
                calcheight(root->left, h + 1);
            if(root->right)
                calcheight(root->right, h + 1);
        }
        height = max(height, h);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        calcheight(root, 0);
        int rows = height + 1, cols = pow(2, height + 1) - 1;
        vector<vector<string>> ans(rows, vector<string>(cols, ""));
        queue<TreeNode*> que1;
        queue<pair<int, int>> que2;
        que1.push(root);
        que2.push(pair<int, int>(0, (cols - 1) / 2));
        ans[0][(cols - 1) / 2] = to_string(root->val);
        while(!que1.empty()){
            int k = que1.size();
            for(int i = 0 ; i < k ; i ++){
                TreeNode* temp = que1.front();
                auto [r, c] = que2.front();
                que1.pop();
                que2.pop();
                if(temp->left){
                    que1.push(temp->left);
                    int row = r + 1;
                    int col = c - pow(2, height - r - 1);
                    ans[row][col] = to_string(temp->left->val);
                    que2.push(pair<int, int>(row, col));
                }
                if(temp->right){
                    que1.push(temp->right);
                    int row = r + 1;
                    int col = c + pow(2, height - r - 1);
                    ans[row][col] = to_string(temp->right->val);
                    que2.push(pair<int, int>(row, col));
                }
            }
        }
        return ans;
    }
};

int main(){

}