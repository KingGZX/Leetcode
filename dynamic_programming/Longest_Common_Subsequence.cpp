/*
Q1143
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

 

示例 1：

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。
示例 2：

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
示例 3：

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // dp思路
    // 用dp[i][j] 表示 text1的第i个字符为止  和   text2的第j个字符为止 的匹配情况
    // 如果text1[i] == text2[j] 的情况下，就是 dp[i - 1][j - 1] + 1
    // 如果两个字符不相等  就应该取  max(dp[i - 1][j], dp[i][j - 1]);

    // 为了方便操作，dp数组设置时扩维，会使上面的转移方程如  i - 1 ||  j - 1 不去遇见越界的情况
    // 但此时比较两个text时就需要索引减一了，否则索引越界，但显然这样写起来仍旧是更加便捷的。
    // defeat   90.05%   50.50%
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.length(), sz2 = text2.length();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
        for(int i = 1 ; i <= sz1 ; i ++){
            for(int j = 1 ; j <= sz2 ; j ++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[sz1][sz2];
    }
};

int main(){
    Solution s;
    s.longestCommonSubsequence("abcde", "ace");
    return 0;
}