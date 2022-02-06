/*
Q160
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。

图示两个链表在节点 c1 开始相交：
题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

自定义评测：

评测系统 的输入如下（你设计的程序 不适用 此输入）：

intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
listA - 第一个链表
listB - 第二个链表
skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。
如果程序能够正确返回相交节点，那么你的解决方案将被 视作正确答案 。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

示例 2：
输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [1,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。

示例 3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
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
    // 下列解法满足了O(1)空间复杂度但并无法满足进阶要求的O(m + n)时间复杂度，因此时间效率只能击败5%
    // 这个暴力求解的算法时间复杂度是O(mn)，因为双重while循环嵌套。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        ListNode* ans = nullptr;
        while(p){
            while(q){
                if(p == q){
                    ans = p;
                    break;
                }
                q = q->next;
            }
            if(ans) break;
            q = headB;
            p = p->next;
        }
        return ans;
    }
    // 利用双指针法
    /*
    case 1：
        headA 或者 headB 有一者为空，那么必不可能相交，直接返回nullptr
    case2：
        令pA = headA，pB = headB，pA不为空时就移动至pA->next，pB同理。
        如果pA为空就移至headB，pB为空后移至headA。
    
    其实用到的证明思路和找入环口很像，证明：
    A链表长度m，B链表长度n。
    假设相交部分长度为c，A抛去相交部分是a，B抛开相交部分长度是b。显然有：
    a + c = m ， b + c = n
    1.m = n
        1.1 有交点，那么a = b，那么两指针同时前进，必然会相遇
        1.2 无交点，那么两指针会同时到达链表尾部，会因为两指针均为nullptr而退出循环返回nullptr

    2. m != n
        2.1 有交点，那么两指针必不会同时为null，且两指针均走过 a + b + c步后会在交点相遇
        2.2 无交点，那么两指针会在同时走过 m + n 步后都变为nullptr而退出循环并返回nullptr
    */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB){
        if(!headA || !headB) return nullptr;
        ListNode* pA = headA, *pB = headB;
        while(pA != pB){
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;
    }
};

int main(){
    return 0;
}