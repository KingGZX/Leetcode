/*
Q680
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: s = "aba"
输出: true
示例 2:

输入: s = "abca"
输出: true
解释: 你可以删除c字符。
示例 3:

输入: s = "abc"
输出: false
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // 两种valid其实对应的是两种删除方式，自己比较难在同一函数内处理，就写成两个，在主函数中用或操作符即可
    // 分别是ptr1和ptr2字符不对应时删除ptr1的字符或者ptr2的字符
    // 用这样的方式可以通过且时间效率挺高的，但内存消耗较大
    // 实际上利用同样的思想可以对下列代码进行优化写于Solution2中
    bool valid_1(string s, int ptr1, int ptr2){
        bool del = true;
        while(ptr1 < ptr2){
            if(s[ptr1] == s[ptr2]){
                ptr1 ++;
                ptr2 --;
            }
            else{
                // 要考虑可以删除的情况
                if(!del) return false;
                if(s[ptr1 + 1] == s[ptr2]){
                    ptr1 += 2;
                    ptr2 --;
                    del = false;
                }
                else return false;
            }
        }
        return true;
    }
    bool valid_2(string s, int ptr1, int ptr2){
        bool del = true;
        while(ptr1 < ptr2){
            if(s[ptr1] == s[ptr2]){
                ptr1 ++;
                ptr2 --;
            }
            else{
                // 要考虑可以删除的情况
                if(!del) return false;
                if(s[ptr2 - 1] == s[ptr1]){
                    ptr2 -= 2;
                    ptr1 ++;
                    del = false;
                }
                else return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int ptr1 = 0, ptr2 = s.length() - 1;
        return valid_1(s, ptr1, ptr2) || valid_2(s, ptr1, ptr2);
    }
};


class Solution2{
    public:
        // 用一个函数执行删除完的比较即可不要全部去重复做一遍
        bool cmp(string s, int p1, int p2){
            for(int i = p1 ; i < p2 ; i ++){
                if(s[i] == s[p2]){
                    p2 --;
                }
                else return false;
            }
            return true;
        }
        bool validPalindrome(string s) {
            int ptr1 = 0, ptr2 = s.length() - 1;
            while(ptr1 < ptr2){
                if(s[ptr1] == s[ptr2]){
                    ptr1 ++;
                    ptr2 --;
                }
                else{
                    return cmp(s, ptr1 + 1, ptr2) || cmp(s, ptr1, ptr2-1);
                }
            }
            return true;
        }
};

int main(){
    Solution s;
    s.validPalindrome("eeccccbebaeeabebccceea");
    return 0;
}