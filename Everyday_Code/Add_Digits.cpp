/*
Q258
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

 

示例 1:
输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。

示例 1:
输入: num = 0
输出: 0
 

提示：
0 <= num <= 231 - 1
 

进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
*/


#include <iostream>
using namespace std;

class Solution {
public:
    // O(1)解法需要数学证明，鉴于此处不易打数学公式
    // 附题解URL：
    // https://leetcode-cn.com/problems/add-digits/solution/ge-wei-xiang-jia-by-leetcode-solution-u4kj/
    int addDigits(int num) {
        if(!num) return num;
        return num % 9 == 0 ? 9 : num % 9;
    }
};

int main(){
    return 0;
}