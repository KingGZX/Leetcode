/*
Q654

给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
*/

#include <iostream>
#include <vector>
using namespace std;


 //Definition for a binary tree node.
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
    TreeNode* root = nullptr;
    int findmaxindex(vector<int>& nums, int left, int right){
        int index = left;
        int mmax = nums[left];
        for(int i = left + 1 ; i < right ; i ++){
            if(nums[i] > mmax){
                mmax = nums[i];
                index = i;
            }
        }
        return index;
    }
    void buildtree(TreeNode* root, vector<int>& nums, int left, int right, bool l){
        if(left == right)
            return;
        int newindex = findmaxindex(nums, left, right);
        TreeNode* temp = new TreeNode(nums[newindex]);
        if(l) root->left = temp;
        else root->right = temp;
        buildtree(temp, nums, left, newindex, true);
        buildtree(temp, nums, newindex + 1, right, false);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int rootindex = findmaxindex(nums, 0, nums.size());
        root = new TreeNode(nums[rootindex]);
        // true代表左子树
        buildtree(root, nums, 0, rootindex, true);
        buildtree(root, nums, rootindex + 1, nums.size(), false);
        return root;
    }
};

int main(){

}