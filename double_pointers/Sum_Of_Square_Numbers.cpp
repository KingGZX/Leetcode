/*
Q633
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 

示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：

输入：c = 3
输出：false
示例 3：

输入：c = 4
输出：true
示例 4：

输入：c = 2
输出：true
示例 5：

输入：c = 1
输出：true
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    // 把这题退化成了Two_SumII的形式来做，比较简单
    bool judgeSquareSum(int c) {
        int num = sqrt(c);
        int ptr1, ptr2;
        ptr1 = 0, ptr2 = num;
        while(ptr1 <= ptr2){   // 以c = 2为例  1 * 1 + 1 * 1 = 2也是可以通过的
            long long temp = pow(ptr1, 2) + pow(ptr2, 2);   // z这里用longlong是因为测试数据中有溢出的的情况
            if(temp > c)
                ptr2 --;
            else if(temp < c)
                ptr1 ++;
            else
                return true;
        }
        return false;
    }
};

int main(){
    return 0;
}