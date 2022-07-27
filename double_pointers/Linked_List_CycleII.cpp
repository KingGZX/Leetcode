/*
Q142
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
解题思路：   快慢指针法
快指针每一轮走两步，慢指针每一轮走一步。
1.若快指针走到了nullptr，那么说明无环
2.否则快指针一定会和慢指针相遇，可以把环想成跑道，快的选手一定会追上慢的选手
[因为没有规定跑多久和跑多少米，是一直跑的！]

假设链表长度为a + b，a代表头结点到入环口结点的结点数量(exclude 入环口本身)，b就是环上的结点数量

假设第一次相遇时快指针走了f步，慢指针走了s步。
显然  f = 2s   ----->  因为两者走的时间是一样的
同时  快指针一定是在走了s步的基础上比慢指针多走了n圈，这样的推导必会相遇
所以  f = s + nb

两式求得  ->    s = nb    f = 2nb


又因为  a + nb 必会在入环口，这个很容易理解，走了a步到达入环口，又绕了n圈还会回到入环口！
所以假设此时我们把快指针重新置位到头结点。
然后两指针速度设为相同，那么两者将会在入环口相遇！！
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow, *quick;
        slow = head, quick = head;
        do{ // I use do---while--- structrue because we initialize the quick & slow pointer at the same location
            // therefore, a pure 'while' structrue may lead to failures as we exit the loop at the first time
            // I don't use quick->next->next because I'm afraid of that quick->next is null then error occurs
            for(int i = 0 ; i < 2 ; i ++){
                if(!quick)
                    return nullptr;
                quick = quick->next;
            }
            // if quick pointer dosen't go wrong then it's impossible that slow pointer gose wrong
            slow = slow->next;
        }while(slow != quick);
        quick = head;
        while(quick != slow){
            quick = quick->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
    return 0;
}