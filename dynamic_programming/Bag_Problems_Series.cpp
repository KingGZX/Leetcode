/*
 * @author: Zhexuan Gu
 * @Date: 2022-07-24 15:25:51
 * @LastEditTime: 2023-01-03 10:52:07
 * @FilePath: /CPPprojects/Leetcode/dynamic_programming/Bag_Problems_Series.cpp
 * @Description: Please implement
 */
/*
背包问题是一种组合优化的NP 完全问题：有N 个物品和容量为W 的背包，每个物品都有
自己的体积w 和价值v，求拿哪些物品可以使得背包所装下物品的总价值最大。如果限定每种物
品只能选择0 个或1 个，则问题称为0-1 背包问题；
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        /*
        动态转移方程：
        对于每一件物体，我们可以选择放入或者不放入，放入的话要利用减去此物体体积情况下的最优解加上此物体带来的收益
        用dp[j]表示对于容量为j时的最优选择方案
        下列方程中，i代表了第i个物体
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]) 
        */
        int knapsack(vector<int> weights, vector<int> values, int N, int W){
            vector<int> dp(W);
            for(int i = 0 ; i < N ; i ++){    // 相当于一个选择过程
                for(int j = W - 1 ; j >= weights[i] ; j --){     // 我们总是要去利用上一轮的最优子结构，
                                                        // 如果正循环岂不是把上一轮的最优子结构覆盖掉了？直接变成了本轮结果。
                                                        // 正循环就会导致某些物品被选中多次
                    dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
                }
            }     
            return dp[W - 1];     
        }


};

int main(){
    return 0;
}