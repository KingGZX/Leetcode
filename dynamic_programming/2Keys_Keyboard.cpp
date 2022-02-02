/*
Q650
最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
Paste（粘贴）：粘贴 上一次 复制的字符。
给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。
返回能够打印出 n 个 'A' 的最少操作次数。

 

示例 1：

输入：3
输出：3
解释：
最初, 只有一个字符 'A'。
第 1 步, 使用 Copy All 操作。
第 2 步, 使用 Paste 操作来获得 'AA'。
第 3 步, 使用 Paste 操作来获得 'AAA'。

示例 2：
输入：n = 1
输出：0
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
    动态规划思路，用dp[i]表示i个字符所需要的最少次数
    用一个变量copy保证当前复制着的字符数
    动态转移方程如下:
        dp[i] = min(dp[i], dp[j] + i / j)
        j 为可以被 i 整除的数，因为如果由不能整除的数转移过来的话只能是用1个'A'不断叠加，就是我们初始化的值，没意义！
        dp[j] 为达到j个字符所用的最小操作数， 那么此时先复制一次 (+ 1)，然后 还需要粘贴(i / j - 1)回，-1是因为已经有j个
        所以加起来就是上面的动态转移方程
    */
    int minSteps(int n) {
        if(n == 1) return 0;
        if(n == 2) return 2;
        vector<int> dp(n + 1, 1e3);
        dp[1] = 1, dp[2] = 2;
        for(int i = 3 ; i <= n ; i ++){
            for(int j = 2 ; j < i ; j ++){
                if(i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }
        return dp[n];
    }

    // 把j的循环稍微优化一下，因为知道一个因子自然就求解出了另外那个因子
    // 能击败双 70%
        int minSteps_opt(int n) {
        vector<int> dp(n + 1);
        for(int i = 2 ; i <= n ; i ++){
            dp[i] = i;
            for(int j = 2 ; j * j < i ; j ++){
                if(i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i / j);
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};

int main(){
    return 0;
}