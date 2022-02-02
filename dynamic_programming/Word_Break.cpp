/*
Q139
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
    DP思路：
        用dp[i]表示字符串前i个(包括i本身)字符是否可以被拼接成功
        对于以第i个字符结尾的情况，我们遍历整个字典:
            查看是否能找到以此字符结尾的子字符串匹配到字典里的字符串
            如果能匹配上 dp[i] = dp[i - len] len为匹配上的字符串长度
        因为我们仍旧需要前边的字符串全是匹配好的
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for(int i = 1 ; i <= n ; i ++){
            for(auto str : wordDict){
                int len = str.length();
                if(i >= len && s.substr(i - len, len) == str){
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};

int main(){
    return 0;
}