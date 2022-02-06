/*
Q24
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode;
        ListNode* prev = head;
        ListNode* nxt = head->next;
        dummy->next = nxt;
        while(nxt){
            ListNode* temp = nxt->next;
            nxt->next = prev;
            prev->next = temp;
            prev = temp;
            nxt = temp->next;
        }
        return dummy->next;
    }
};

int main(){
    return 0;
}