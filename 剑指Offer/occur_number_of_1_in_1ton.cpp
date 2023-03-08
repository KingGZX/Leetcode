/*
 * @author: Zhexuan Gu
 * @Date: 2023-03-04 16:22:50
 * @LastEditTime: 2023-03-08 14:01:04
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/occur_number_of_1_in_1ton.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
剑指 Offer 43. 1～n 整数中 1 出现的次数
难度: 困难

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：
输入：n = 12
输出：5

示例 2：
输入：n = 13
输出：6
*/

// naive thinking: brute loop and time complexity O(nlogn)
class Solution {
public:
    int helper(int n){
        int cnt = 0;
        while(n){
            cnt += (n % 10 == 1 ? 1 : 0);
            n /= 10;
        }
        return cnt;
    }
    int countDigitOne(int n) {
        int ans = 0;
        for(int i = 1 ; i <= n ; ++ i){
            ans += helper(i);
        }
        return ans;
    }
};


// 数位DP 具体思路见 刷题笔记 Page 16  Time Complexity O(logn)
class Solution2{
public:
    int countDigitOne(int n) {
        int ans = 0;
        long long digit = 1;
        int high = n / 10;
        int low = 0;
        int cur = n % 10;
        while(high != 0 || cur != 0){
            if(cur == 0) ans += high * digit;
            else if(cur == 1) ans += high * digit + low + 1;
            else ans += (high + 1) * digit;
            digit *= 10;
            cur = n % (digit * 10) / digit;
            high = n / (digit * 10);
            low = n % (digit * 10) % digit;
        }
        return ans;
    }
};



int main(){
    return 0;
}