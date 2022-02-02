/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：

输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

输入：n = 13
输出：2
解释：13 = 4 + 9
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    思路：用dp[i]表示正整数i所需要的最小的最小的完全平方数
    如果本身就是完全平方数那么dp值为1即可
    否则的话从比次数小的数里 不断取最小的 dp[k] + dp[i - k]
    */
    int numSquares(int n) {
        if(n == 1 || n == 2 || n == 3) return n;
        vector<int> dp(n + 1, 1e4);  // 题目给定的最大n是1e4
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for(int i = 4 ; i <= n ; i ++){
            int k = sqrt(i);
            if(k * k == i) dp[i] = 1;
            else{
                for(int j = 1 ; j <= i / 2 ; j ++){
                    dp[i] = min(dp[i], dp[j] + dp[i - j]);
                }
            }
        }
        return dp[n];
    }
    // 事实证明，上述解法会超时。虽然我们也在利用最优子结构了，但这个循环总是不是很尽如人意，复杂度为O(n²)
    // 下面是自己优化的解法二，已经可以顺利刷掉题目，但效率仍旧不是特别好
    // 思路是保存下所有完全平方数，然后就从这些完全平方数中去解当前最优值，肯定是完全平方数本身来dp 可以满足调用最优结构
    int numSquares2(int n) {
        if(n == 1 || n == 2 || n == 3) return n;
        vector<int> dp(n + 1, 1e4);  // 题目给定的最大n是1e4
        vector<int> temp;
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        temp.push_back(1);
        for(int i = 4 ; i <= n ; i ++){
            int k = sqrt(i);
            if(k * k == i){
                dp[i] = 1;
                temp.push_back(i);
            }
            else{
                for(auto elem : temp){
                    dp[i] = min(dp[i], 1 + dp[i - elem]);  // 因为elem都是完全平方数
                }
            }
        }
        return dp[n];
    }
    // 实际上官方解法的思路也是一直的
    // 就是状态转移方程都是从本身减去一些完全平方数   比如12 转移到 dp[10]没意义，dp[10]本身也是由最优的dp[9] + dp[1]构成
    // 所以dp[12] 会主动去搜 dp[9] + dp[3] 即 ---> dp[10] + dp[2] == dp[9] + dp[1] + dp[2] === dp[9] + dp[3]
    // 总之就是转移完全平方数的距离才有意义
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for(int i = 1 ; i <= n ; i ++){
            dp[i] = INT32_MAX;
            for(int j = 1 ; j * j < i ; j ++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main(){
    return 0;
}