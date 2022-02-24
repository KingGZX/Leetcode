/*
Q109
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:
给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    // 注意题目要求我们平衡，所以我们尽量要从中点去找结点
    // 链表刷题时，讲解过如何快速找中点
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = buildTree(head, nullptr);
        return root;
    }
    // 一开始尝试的是找到中点，然后令中点前面结点和中点断开连接
    // 这样的方案并不好，甚至可以说很难办
    TreeNode* buildTree(ListNode* head, ListNode* tail){
        if(head == tail)
            return nullptr;
        ListNode* mid = midPoint(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(head, mid);
        root->right = buildTree(mid->next, tail);
        return root;
    }

    // 快慢指针法快速求解中间结点
    ListNode* midPoint(ListNode* head, ListNode* tail){
        // 例： 1->2->3       1->2->3->4
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast->next != tail && fast->next->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }



    // 以题目中的实例为模板进行一次完整的流程  -10->-3->0->5->9
    /*
    1.  mid = 0, root = 0, temp = 5, 结点0被修改为空指针  root->left = xxxx(-10)    root>right = xxxx(5)
    2.  mid = -10, root = -10, temp = -3, 结点-10被修改为空指针，root->left = xxxx(nullptr[因为-10被修改了]), root->right = xxxx(-3)
    3.  mid = -3, root = -3, temp = nullptr, 结点-3被修改为nullptr, root->left = xxxx(nullptr[因为-3被修改]), root->right = xxxx(nullptr)
    4.  
    5.
    */
};

int main(int argc, const char** argv) {
    vector<int> vec{-10, -3, 0, 5, 9};
    ListNode* head = new ListNode(-10);
    ListNode* p = head;
    for(int i = 1 ; i < vec.size() ; i ++){
        ListNode* temp = new ListNode(vec[i]);
        p->next = temp;
        p = p->next;
    }
    Solution s;
    s.sortedListToBST(head);
    return 0;
}