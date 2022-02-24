/*
Q236
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。

示例 3：
输入：root = [1,2], p = 1, q = 2
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
    int maxHeight = 0;
    int cur = 1;
    TreeNode* ans;
    /*
    // 这里是第一种思路，isRoot辅助函数就是判断某个节点是否可以成为p 和 q的根
    // 我们用cnt来计数是否遍历到这两个结点，为2时代表两个全可以访问到，可以成为根，
    // 主函数执行先序遍历，用cur表示当前结点深度，maxHeight表示最深的可以成为公共祖先的深度
    // 如果某一结点不能成为公共祖先，那么停止其子树的递归，如果某一结点就是p or q 本身，也可以停止递归
    // (比如 root已经等于p了，那么root子树必然不会再成为p的根啊，也就必然可以停止递归了)
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root){
            int cnt = 0;
            isRoot(root, p, q, cnt);
            if(cnt == 2 && cur > maxHeight){
                maxHeight = cur;
                ans = root;
            }
            if(cnt != 2){
                return ans;
            }
            if(root == p || root == q){
                return ans;
            }
            cur ++;
            lowestCommonAncestor(root->left, p, q);
            lowestCommonAncestor(root->right, p, q);
            cur --;
        }
        return ans;
    }

    void isRoot(TreeNode* root, TreeNode* p, TreeNode* q, int& cnt){
        if(cnt == 2)
            return;
        if(root){
            if(root->val == p->val || root->val == q->val){
                cnt++;
            }
            isRoot(root->left, p, q, cnt);
            isRoot(root->right, p, q, cnt);
        }
    }

    */

    // 考虑满足LCA，最近公共祖先的条件：假设我们含有一个结点x，fx表示x的子树中是否含有p q结点 可以将表达式写出
    // ((f_left && f_right) || ((f == p || f == q) && (f_left || f_right)))
    // 含义就是 x结点的左子树和右子树均为true的情况下，那么x本身就是LCA
    // 或者说x结点本身已经是p or q了，且其左子树或者右子树上包含了另一结点，那么也是成立的
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return false;
        }
        bool flag1 = dfs(root->left, p, q);
        bool flag2 = dfs(root->right, p, q);
        if((flag1 && flag2) || ((root->val == p->val || root->val == q->val) && (flag1 || flag2))){
            ans = root;
            // 这里无需担心因为满足以上条件的有且仅有那么一个ans
            // 我一开始想起来也感觉比较困难，但多模拟一些例子你就会发现，这个ans被找到后不会再被更新为错误的值
        }
        return flag1 || flag2 || root->val == p->val || root->val == q->val;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
