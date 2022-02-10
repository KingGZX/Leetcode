/*
Q148
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

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
    // 最开始的简单思路是将链表所有元素装入容器，对容器调用sort(O(nlongn)时间复杂度)
    // 然后用建链表的思路将容器内排好序的元素一个个插入尾部
    // 空间复杂度不满足O(1)，为O(n)
    
    // 进阶算法要求我们在O(1)空间复杂度下实现排序
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        // 先统计链表总长度
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length ++;
            temp = temp->next;
        }
        // 新建一个头结点链接原链表
        ListNode* dummy = new ListNode(-1, head);
        // 从初始长度1开始，不断从这个长度开始对链表进行分组排序，每一轮结束长度变为原先两倍
        for(int subLength = 1 ; subLength < length ; subLength <<= 1){
            // 找到待排序分组的首尾位置
            ListNode* prev = dummy, *curr = dummy->next;
            while(curr){
                // cur作为前半分组的头结点，我们去找后半分组的头结点head2
                ListNode* head1 = curr;
                // 由于我们用subLength控制本轮排序长度，因此findMidpoint辅助函数在这儿并没有用
                for(int i = 1 ; i < subLength && curr->next ; i ++){
                    curr = curr ->next;
                }
                // 找到了后半分组的头结点head2
                ListNode* head2 = curr->next;
                // 截断前半分组尾部(不能让其继续链着head2)，否则merge时候出问题
                curr->next = nullptr;
                curr = head2;
                // 遍历到head2后半分组的尾部然后截断后半分组和整个链表的关系
                for(int i = 1 ; i < subLength && curr && curr->next; i ++){
                    curr = curr->next;
                }
                // 通过遍历，curr要么在nullptr了，要么就是在分组的尾结点了
                // 执行切割前要先判断是不是nullptr先
                ListNode* next = nullptr;
                if(curr){
                    next = curr->next;  // 保留好后面的所有结点
                    curr->next = nullptr;
                }
                // 对两分组进行归并！
                ListNode* merged = Merge(head1, head2);
                // 把这个有序链表先放到新建头结点后面
                prev->next = merged;
                // 更新prev和curr
                while(prev->next){
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummy->next;
    }

    ListNode* findMidpoint(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* Merge(ListNode* head1, ListNode* head2){
        ListNode* p = head1;
        ListNode* q = head2;
        ListNode* temp = new ListNode(0);
        ListNode* ptr = temp;
        while(p && q){
            if(p->val <= q->val){
                ptr->next = p;
                p = p->next;
            }
            else{
                ptr->next = q;
                q = q->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (p != nullptr ? p : q);   // 链表合并这个语句比较精妙得记住，不要再去调双循环，那样很慢
        return temp->next;
    }
};

int main(){
    return 0;
}