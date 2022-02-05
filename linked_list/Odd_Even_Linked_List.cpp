/*
Q328
给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

示例 1:
输入: head = [1,2,3,4,5]
输出: [1,3,5,2,4]

示例 2:
输入: head = [2,1,3,5,6,4,7]
输出: [2,3,6,7,1,5,4]
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
    // 算法时间复杂度尚可，因为是符合O(n)时间复杂度的。但显然不满足O(1)的空间复杂度。因为new了同样数量新结点
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* p = odd_head;
        ListNode* q = even_head;
        ListNode* p1 = p;
        ListNode* q1 = q;
        while(p){
            if(!p->next || !p->next->next){
                odd_head->next = nullptr;
                break;
            }
            else{
                ListNode* temp = new ListNode(p->next->next->val);
                ListNode* tmp = p->next->next;
                odd_head->next = temp;
                odd_head = odd_head->next;
                p = tmp;
            }
        }
        while(q){
            if(!q->next || !q->next->next){
                even_head->next = nullptr;
                break;
            }
            else{
                ListNode* tmp = q->next->next;
                ListNode* temp = new ListNode(q->next->next->val);
                even_head->next = temp;
                even_head = even_head->next;
                q = tmp;
            }
        }
        while(p1->next){
            p1 = p1->next;
        }
        p1->next = q1;
        return head;
    }
    // 下列代码才是正解
    // 直接在同一循环内交叉着做即可，就不会有分开来处理奇偶后某个节点的next被修改的现象
    // 因此也就无需动态分配结点这一操作了，实现了空间复杂度O(1)
    // 为什么可以交叉做的理由:even总在odd后面，假如odd先变空，even必空；even先变空但odd不为空，其实odd就是原链表最后一个结点
    // 当然，没到null的话，奇的next变为偶的next并把奇移至next，做偶时先去判断奇next是不是空，是空就别取next
    ListNode* oddEvenList2(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* odd = head, *even = head->next;
        ListNode* p = odd, *q = even;
        while(odd && even){
            odd->next = even->next;
            odd = odd->next;
            even->next = (odd == nullptr ? nullptr : odd->next);
            even = even->next;
        }
        while(p->next){
            p = p->next;
        }
        p->next = q;
        return head;
    }
};


int main(){
    return 0;
}