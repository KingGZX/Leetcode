/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-16 10:22:49
 * @LastEditTime: 2023-01-16 11:42:28
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/n_dice.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:
输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]

示例 2:
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556
*/

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> ans(6, 1.0 / 6.0);
        for(int i = 2 ; i <= n ; i ++){
            vector<double> prev = ans;
            ans.clear();
            ans.resize(5 * i + 1);
            for(int j = i ; j <= 6 * i ; j ++){
                for(int k = 1 ; k <= 6 && k < j ; k ++){
                    if(j - k <= 6 * (i - 1) && j - k >= i - 1)
                        ans[j - i] += prev[j - k - (i - 1)] / 6;
                }
            }
        }
        return ans;
    }
};

/*
用到的是很神奇的dp的思想

首先我们知道n个骰子能组成的范围是   [n, 6*n] 共 5n + 1 个数

比如说我们知道了 n = 1 时的概率 [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]

那现在要知道 n = 2 时的情况，就是相当于在 n = 1 的情况下加上一个骰子
此时如果我想知道 和 = 3 的概率，我仅需观察 n = 1时的 和 = 1 或 2的概率即可，此时再配合第二个骰子的1或2即可实现

所以 sum = 3 的概率为
Prob(1) * 6 + Prob(2) * 6 / 6^2 = (Prob(1) + Prob(2)) / 6

我写成上述形式就是用了计数的形式，就是先求出前 n - 1 个骰子组成数 的概率 * 6^(n - 1) 为计数
然后现在要除以当前的总可能数 6^n 简化后就是之前的概率乘以 1/6 求和
*/

int main(){
    Solution s;
    vector<double> vec = s.dicesProbability(3);
    for(const double& elem : vec){
        cout << elem << " ";
    }
    return 0;
}