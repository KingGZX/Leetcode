/*
Q10
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 
可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5：

输入：s = "mississippi" p = "mis*is*p*."
输出：false
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 用这种方式很难判断 * 号时指针要不要移动
    // 总之，操作起来并不是非常方便
    bool isMatch(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        int ptr1 = 0, ptr2 = 0;
        char prev = ' ';
        while(ptr1 < sl && ptr2 < pl){
            if(s[ptr1] == p[ptr2]){
                ptr1 ++;
                ptr2 ++;
            }
            else{
                if(p[ptr2] == '.'){
                    ptr1 ++;
                    ptr2 ++;
                }
                else if(p[ptr2] == '*'){
                    if(ptr2 + 1 < pl && p[ptr2 + 1] == s[ptr1]){
                        ptr1 ++;
                        ptr2 ++;
                    }
                    else if(prev == '.' && ptr1 - 1 >= 0 && s[ptr1] == s[ptr1 - 1]){
                        ptr1 ++;
                    }
                }
                else{
                    return false;
                }
            }
            prev = p[ptr2];
        }
        if(ptr1 == sl && ptr2 == pl) return true;
        return false;
    }

    //既然被收录在 dynamic programming中，自然学会用DP来解题
    bool isMatch_DP(){
        
    }

};

int main(){
    return 0;
}