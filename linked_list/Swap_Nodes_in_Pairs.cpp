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
        ListNode* temp = dummy;
        // 用一个指针保留上一次的接口，连接口
        // 将prev和nxt全部转换为下一组要执行的交换结点
        // 如果下一组的prev就为null 或者说 nxt为null 那么均可以直接链到prev上然后结束                    
        while(prev){
            ListNode* _prev = nxt->next;    // 下一组要交换的节点的前者
            temp->next = nxt;
            temp->next->next = prev;
            temp = prev;
            if(!_prev || !_prev->next){
                temp->next = _prev;
                break;
            }
            else{
                prev = _prev;
                nxt = _prev->next;
            }
        }
        return dummy->next;
    }
};

int main(){
    return 0;
}