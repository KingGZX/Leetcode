/*
剑指 Offer II 051. 节点之和最大的路径
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给定一个二叉树的根节点 root ，返回其 最大路径和，即所有路径上节点值之和的最大值。

 

示例 1：
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

示例 2：
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> routeLen;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int leftsum = 0, rightsum = 0;
        // if(root->left){
            leftsum = helper(root->left);
            // routeLen.push_back(leftsum);
        // }
        // if(root->right){
            rightsum = helper(root->right);
            // routeLen.push_back(rightsum);
        // }
        // routeLen.push_back(root->val);
        /*
        ----------------三个注意点--------------
        1. 不能返回 当前根+左和+右和，这样的话其本身就形成了一条完整路径，不能和递归下来的节点再合并了，
           因此只能选取 根+左 或 根+右 或者 单独根 去和自己的父节点合并

        2. 由于我们在1中说了不能返回 当前根+左和+右和， 那么这个值别忘了存起来！ 否则就漏掉了一个可行解！

        3. 无需单独存储 leftsum 和 rightsum, 因为在执行helper递归时， 这两个值在更深层已经存进来了
        */
        routeLen.push_back(root->val + leftsum + rightsum);
        int localmax = max(max(root->val + leftsum, root->val + rightsum), root->val);
        // localmax = max(localmax, root->val + leftsum + rightsum);
        routeLen.push_back(localmax);
        return localmax;
    }
    int maxPathSum(TreeNode* root) {
        /*
        核心思想还是通过树的遍历来获取所有的可能路径之和, 然后sort筛选最大
        */
        helper(root);
        sort(routeLen.begin(), routeLen.end(), [](const int& a, const int& b){
            return a > b;
        });
        return routeLen[0];
    }
};

int main(){

}