/*
Q206
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
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
    /*
    如果链表为空或者说只有一个元素，那么直接返回头结点即可。
    否则我们应该先找到当前节点的next进行保存
    并且维护一个变量为先前结点
    修改过程如下：
        当前结点next修改为先前结点
        先前结点更新为当前结点
        当前结点更新为next结点
    */
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curt = head;
        while(curt){
            ListNode* temp = curt->next;
            curt->next = prev;
            prev = curt;
            curt = temp;
        }
        return prev;
    }
};

int main(){
    return 0;
}