/*
Q76
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
1.显然一种较为简单的方式用brute force从s的每一个位置出发找到包含t的最小字符串
然后每次一找到就更新最小值。
显然这个方式就是O(n²)的，题目要求我们O(n)时间复杂度内解决此问题
*/

class Solution {
public:
    /*
    Slide Window，滑动窗口算法，在Computer Network中TCP流量控制也用到了这种思想
    显然也是归类于双指针范畴内的
    */
    string minWindow(string s, string t) {
        // 先用一个容器来记录某个字母是否出现
        map<char, bool> mp1;
        // 用一个容器统计字符出现的次数
        map<char, int> mp2;
        // 对模式串进行统计
        for(auto ch : t){
            mp1[ch] = true;
            mp2[ch] ++;
        }
        // 滑动窗口算法核心操作
        int l_ptr = 0, r_ptr = 0;   // 两指针，称为“左指针”和“右指针”
        int min_size = s.size() + 1 ;   // 记录最后的答案字符串的size，产生更小的时候要更新此指
        int min_left = 0        ;   // 记录最后的答案字符串的左边界，利用substr api可以截取出此解
        int cnt = 0             ;   // 记录当前包含多少char了，和t的size相同时说明匹配上了
        for(r_ptr = 0 ; r_ptr < s.length() ; r_ptr ++){   // 持续移动右指针
            if(mp1[s[r_ptr]]){    // 遍历到的字符是所需字符，进行处理
                if(-- mp2[s[r_ptr]] >= 0){    // 说明此字符有剩余，也就是说原本还是缺这个字符的 如果<0说明这个字符偏多了
                    cnt ++;
                }
                while(cnt == t.size()){    // 如果某个位置时已经包含了t字符串所需的所有字符了
                    if(r_ptr - l_ptr + 1 < min_size){   // 如果当前窗口大小小于原先维护的值，进行更新
                        min_size = r_ptr - l_ptr + 1;
                        min_left = l_ptr;
                    }
                    if(mp1[s[l_ptr]] && ++ mp2[s[l_ptr]] > 0){    // 开始移动左指针
                        // 如上条件意为：左指针移动后把移动前指向的那个字母加还回去，其值>0，也就是不够了
                        // 此时减去cnt 破坏条件，意为无法完全包含了！
                        -- cnt;
                    }
                    l_ptr ++;
                }
            }
        }
        return min_size > s.size() ? " " : s.substr(min_left, min_size);
    }
};

int main(){
    Solution s;
    s.minWindow("ADOBECODEBANC", "ABC");

    return 0;
}