/*
Q116
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

示例 1：
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]

示例 2:
输入：root = []
输出：[]
*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
题目的含义就是同一层的那些结点用next链起来，从左到右的顺序，最右边那个链到null
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 层序遍历+添加指针

        // 不难理解，但没满足题目的进阶要求，就是不用队列这一额外空间
        if(!root)
            return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int k = que.size();
            for(int i = 0 ; i < k ; i ++){
                Node* temp = que.front();
                que.pop();
                if(i + 1 >= k)
                    temp->next = nullptr;
                else
                    temp->next = que.front();
                if(temp->left){
                    que.push(temp->left);
                    que.push(temp->right);
                }
            }
        }
        return root;
    }

    Node* connect(Node* root) {

    }
};

int main(){
    return 0;
}