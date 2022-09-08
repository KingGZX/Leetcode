/*
Q652

给定一棵二叉树 root，返回所有重复的子树。
对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
如果两棵树具有相同的结构和相同的结点值，则它们是重复的。
 

示例 1：
输入：root = [1,2,3,4,null,2,4,null,null,4]
输出：[[2,4],[4]]


示例 2：
输入：root = [2,1,1]
输出：[[1]]


示例 3：
输入：root = [2,2,2,3,null,3,null]
输出：[[2,3],[3]]
*/


#include <iostream>
#include <vector>
#include <map>
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
    // 一开始的思路是疯狂递归，然后把结点用map打标记。
    // 但发现这样的形式很难控制结构不重复这一点
    // 学习了官方的思路，就是把一颗子树序列化为字符串，然后比对字符串即可
    map<string, int> mp;
    vector<TreeNode*> ans;
    string serialize(TreeNode* root){
        if(root){
            string mySeries = to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")";
            mp[mySeries] ++;
            if(mp[mySeries] == 2)
                ans.push_back(root);
            return mySeries;
        }
        return "";
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return ans;
    }
};