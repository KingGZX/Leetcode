/*
Q524
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，
该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

 

示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 自己的想法比较暴力
    // cmp函数利用双指针法比较字典里的某一字符串和给定的字符串能否匹配上，主函数则循环遍历字典中的每一字符串
    // 若要更新返回的答案字符串，则需能匹配 + (当前匹配上的字符串长度比之前保留的答案长或者长度相等情况下但字典序更小)
    bool cmp(string s1, string s2){
        int ptr1, ptr2;
        ptr1 = ptr2 = 0;
        while(ptr1 < s1.length() && ptr2 < s2.length()){
            if(ptr2 == s2.length())
                return true;
            if(s1[ptr1] == s2[ptr2]){
                ptr2++;
            }
            ptr1++;
        }
        if(ptr2 == s2.length())
            return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(int i = 0 ; i < dictionary.size() ; i ++){
            if(cmp(s, dictionary[i]) && (dictionary[i].length() > ans.length() || 
            (dictionary[i].length() == ans.length() && dictionary[i] < ans))){
                ans = dictionary[i];
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}