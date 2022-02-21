/*
Q530
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。 
示例 1：
输入：root = [4,2,6,1,3]
输出：1

示例 2：
输入：root = [1,0,48,null,null,12,49]
输出：1
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
    // 用先序遍历可以使二叉搜索树以递增方式输出，那么最小差值必然出现在相邻两个之间
    int ans = INT32_MAX;
    int pre = -1e5;   // 因为绝对值差值最大是1e5，题目中有给到Node.val的取值范围
    int cur = 0;
    int getMinimumDifference(TreeNode* root) {
        if(root){
            getMinimumDifference(root->left);
            cur = root->val;
            ans = min(ans, cur - pre);
            pre = cur;
            getMinimumDifference(root->right);
        }
        return ans;
    }
};

int int main(int argc, const char** argv) {
    return 0;
}