/*
 * @author: Zhexuan Gu
 * @Date: 2023-03-01 13:12:39
 * @LastEditTime: 2023-03-01 13:12:50
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/string_permutation.cpp
 * @Description: Please implement
 */

/*
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void backtrack(string s, vector<bool> visit, string& str){
        if(str.length() == s.length()){
            ans.push_back(str);
            return;
        }
        for(int i = 0 ; i < s.length() ; i ++){
            /*
            如果此前的位置未被访问说明是回溯回来之后取得当前位置，那么如果当前位置和之前位置的
            字符相同，可以直接剪枝避免无效搜索。
            反之，若前面的位置visit为true，那么仅仅是一次顺序执行而已不能舍去，否则会少部分答案
            */
            if(i > 0 && s[i] == s[i - 1] && !visit[i - 1]) continue;
            if(!visit[i]){
                visit[i] = true;
                str += s[i];
                backtrack(s, visit, str);
                str.pop_back();
                visit[i] = false;
            }
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<bool> visit(s.length(), false);
        string str = "";
        backtrack(s, visit, str);
        return ans;
    }
};