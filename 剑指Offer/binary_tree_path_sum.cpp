/*
 * @author: Zhexuan Gu
 * @Date: 2023-03-02 19:30:05
 * @LastEditTime: 2023-03-03 19:57:26
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/binary_tree_path_sum.cpp
 * @Description: Please implement
 */
/*
剑指 Offer 34. 二叉树中和为某一值的路径
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

示例 1：


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：



输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
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
    vector<vector<int>> ans;
    void search(TreeNode* root, int target, int& cur, vector<int>& vec){
        if(root){
            // 就是在递归的搜索过程中加一个 叶子判断和从根开始到当前节点之和，并用一个vector记录此路径，并不难
            vec.push_back(root->val);
            cur += root->val;
            if(root->left) search(root->left, target, cur, vec);
            if(root->right) search(root->right, target, cur, vec);
            if(!root->left && !root->right && cur == target){
                ans.push_back(vec);
            }
            cur -= root->val;
            vec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> vec;
        int cur = 0;
        search(root, target, cur, vec);
        return ans;
    }
};

int main(){
    return 0;
}