/*
Q455
对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

输入: g = [1,2,3], s = [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            /*
            解题思路很简单，对于某一个孩子的需求，只要用最小的能满足胃口的饼干即可。

            先对两个数组进行排序，都是从小到大时我们就可以从头开始逐一遍历对比
            饼干大小的指针必须一直往前加，但人的胃口指针未必，因为有时候饼干大小未必能满足胃口！
            */
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int ptr1, ptr2;
            ptr1 = ptr2 = 0;
            int num = 0;
            while(ptr1 < g.size() && ptr2 < s.size()){
                if(s[ptr2] >= g[ptr1]){
                    ptr1 ++;
                    num ++;
                }
                ptr2 ++;
            }
            return num;
        }
};

int main(){
    return 0;
}