/*
Q583
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

示例 1：
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"

示例  2:
输入：word1 = "leetcode", word2 = "etco"
输出：4
*/




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 先求最长公共子序列然后分别用长度减去这个长度即实现
        int len1 = word1.length();
        int len2 = word2.length();
        // 故意开大边界，在写dp时会更加方便
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[i][j]表示word1的 0 ~ i子字符串和 word2的 0 ~ j 子字符串最长公共子串长度
        for(int i = 1 ; i <= len1 ; i ++){
            for(int j = 1 ; j <= len2 ; j ++){
                if(word1[i - 1] == word2[j - 1]){
                    // 字符匹配，新结果就是前面的最优子结果 + 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    // 匹配不上，就去继承前面子字符串的结果，用到了最优子结构
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        // dp[len1][len2]就是最长公共子序列 LCS
        int ans = len1 + len2 - dp[len1][len2] * 2;
        return ans;
    }
};

int main(){
    return 0;
}