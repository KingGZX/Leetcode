#include <iostream>
#include <vector>
#include <queue>

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

class Solution1 {
public:
    /*
    BFS,思路很简单。一直层序遍历至depth-2层。将那一层的节点全部放置在队列中。
    跳出循环，为队列里的节点新建新建一行即可。
    */
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        int cnt = 1;
        queue<TreeNode*> que;
        que.push(root);
        while(cnt < depth - 1){
            int sz = que.size();
            for(int i = 0 ; i < sz ; i ++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
            }
            cnt ++;
        }
        int sz = que.size();
        // 此时queue中保留的是需要新加的那一层的上一层
        for(int i = 0 ; i < sz ; i ++){
            TreeNode* templeft = new TreeNode(val);
            TreeNode* tempright = new TreeNode(val);
            TreeNode* father = que.front();
            que.pop();
            templeft->left = father->left;
            father->left = templeft;
            tempright->right = father->right;
            father->right = tempright;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // 用DFS可以省去queue的空间
        // 但其实递归本身会占用栈空间，所以不见得内存效率会高很多
        if(!root)
            return root;
        if(depth == 1){
            // 根据题意，如果depth为1，则新建一个根结点值为val，且将原树挂到新根的左子树上。
            return new TreeNode(val, root, nullptr);
        }
        if(depth == 2){
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }
        else{
            root->left = addOneRow(root->left, val, depth - 1);
            root->right = addOneRow(root->right, val, depth - 1);
        }
        return root;
    }
};

int main(){
    return 0;
}