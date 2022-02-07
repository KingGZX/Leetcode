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
        
    }
};

int main(){
    return 0;
}