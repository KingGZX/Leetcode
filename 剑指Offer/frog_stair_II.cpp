/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-13 15:24:28
 * @LastEditTime: 2023-01-13 15:29:42
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/frog_stair_II.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1
*/

class Solution {
private:
    const int res = 1e9+7;
public:
    int numWays(int n) {
        // 非常简单的dp 
        // 比如上台阶为3的方式 可以从台阶1走一步2上到 也可以通过台阶2走一步1上到
        if(n <= 2) return n;
        int prev1 = 1, prev2 = 2;
        int ans;
        for(int i = 3 ; i <= n ; i ++){
            ans = (prev1 + prev2) % res;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};

int main(){
    return 0;
}