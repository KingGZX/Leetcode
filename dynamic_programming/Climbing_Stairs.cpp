/*
Q70
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    动态规划思想以及转移方程:
        前两级台阶很好算，自己手动算一算就可以直接return了。
        但对于一个较大的n我们考虑如下：
        我们可以从 第n - 1级台阶走一步上来， 也可以从 第n - 2级台阶走两步上到位置。
        因此 转移方程就是 dp[n] = dp[n - 1] + dp[n - 2]

        代码实现中我们不开dp数组，因为其会浪费较多的空间，由于只与前两项有关，所有就用两个int存值
    */
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        int prev1 = 1, prev2 = 2;
        int ans;
        for(int i = 3 ; i <= n ; i ++){
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};

int main(){
    return 0;
}