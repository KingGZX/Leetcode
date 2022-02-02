/*
Q322
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
*/


#include <iostream>
#include <vector>
using namespace std;


// 我觉得第一想法很容易想到贪心，但贪心的弊端就在于你不知道你不断选取最大面值硬币最后剩下来的部分能否整除等。
// 所以就会退化为回溯，那最后其实就是暴力求解了。
class Solution {
public:
    // 相当于给定容量的背包 放最少的物品 且物品不限次数
    // 用dp[i][j] 表示 容量为i的情况下，用到前j种硬币的最少硬币数量
    // 动态转移方程：
    // 如果当前硬币值 coin[j] == i， 则dp[i][j] = 1
    // 如果当前硬币值 coin[j] > i， 则dp[i][j] = dp[i][j - 1]，因为当前这个太大了，去继承前面的策略即可
    // 最后就是当前硬币值 coin[j] < i，则 dp[i][j] = min(min(dp[i][j], dp[i - coin[j]][j] + 1), dp[i][j - 1])
    // 我们比较了两次min 是为了防止 dp[i - coin[j]][j]是个无法求解的麻烦值(即满足我们返回-1的条件)

    // defeat    5.02%   5.02%
    // 做得很菜，需要优化
    /*
    class Solution {
    public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        int sz = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(sz + 1, 1e5));
        for(int i = 1 ; i <= amount ; i ++){
            for(int j = 1 ; j <= sz ; j ++){
                if(i == coins[j - 1]) dp[i][j] = 1;
                else if(i > coins[j - 1]){
                    dp[i][j] = min(min(dp[i][j], dp[i - coins[j - 1]][j] + 1), dp[i][j - 1]);
                }
                else dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[amount][sz] == 1e5 ? -1 : dp[amount][sz];
    }
};
    */



   // 优化为一维，虽然时间复杂度不变，但因为数组索引变快，最后仍旧有大幅提升
   // 思路仍旧是不变的，dp[i] 代表i元所需要的最小的硬币数 初始化为一个较大值，最后仍旧是这个值的话就是没有解，返回-1
   // 显然我们用dp[i][j] 表示容量为i的情况下，用到前j种硬币的最少硬币数量  这里前j种硬币的讨论是多余的
   // 我们直接把最小值记在dp[i]就足矣。
   // 代码也做了小修小改
   // 比如配上了break
   // 删去了 i < coin[j]的情况(此硬币用不到)，因为这种情况下dp[i]这个位置会默认被那些可行解占领，因为我们优化为一维了
   // 二维情况下我们需要去继承dp[i][j - 1]的情况 否则会因为此处没被修改而保持初始大值

   // defeat 30%   40%
   // 网络较好情况下   50%   80%
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        int sz = coins.size();
        vector<int> dp(amount + 1, 1e5);
        for(int i = 1 ; i <= amount ; i ++){
            for(int j = 0 ; j < sz ; j ++){
                if(i == coins[j]){
                    dp[i] = 1;
                    break;
                }
                if(i > coins[j]){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == 1e5 ? -1 : dp[amount];
    }



};

int main(){
    vector<int> vec{1, 2, 5};
    Solution s;
    s.coinChange(vec, 11);
    return 0;
}