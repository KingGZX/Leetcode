/*
Q234
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：
输入：head = [1,2,2,1]
输出：true

示例 2：
输入：head = [1,2]
输出：false
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
    // O(n)时间复杂度和O(1)空间复杂度

    // O(n) / O(n) 应该较简单，可以开一个数组保留value，然后在数组上操作
    // 也可以另开一个链表，作为原链表的反转，然后逐个对比元素value。

    /*
    1.找到前半部分链表的尾节点。
    2.反转后半部分链表。
    3.判断是否回文。
    4.恢复链表。
    5.返回结果。
    */
    bool isPalindrome(ListNode* head) {
        // 用快慢指针法迅速找到中点位置
        // 1->2->2->1
        // 1->2->3->2->1
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }   // 用上面两个奇偶长度链表模拟一下结束时slow在何处就能正确传参
        // slow就是前半部分尾结点
        ListNode* temp = reverseList(slow->next);

        // 进行对比
        ListNode* p = temp;
        ListNode* q = head;
        bool ans = true;
        while(p){
            if(p->val != q->val){
                ans = false;
                break;
            }
            p = p->next, q = q->next;
        }

        temp = reverseList(temp);
        return ans;
    }

    ListNode* reverseList(ListNode* head){
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