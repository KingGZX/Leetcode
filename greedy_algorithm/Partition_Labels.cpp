/*
Q763
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
返回一个表示每个字符串片段的长度的列表。

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
代码思想：
    先用一张map统计各个字符出现的数量，统计完到时候看哪个字符串的所有字符都已经出现完毕会更加方便

    num用于统计当前字符串所有字母还有多少次没出现！
    prev用于记录上次分割字符串的位置，因为答案要求我们记录的是长度。。得减去上一次的位置
    alpha是一个bool数组，用于看看哪些字符是出现过的
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        bool alpha[26] = {false};
        vector<int> nums;
        map<char, int> mp;
        for(auto ch : s){
            mp[ch] ++;
        }
        int num = mp[s[0]] - 1;
        int prev = 0;
        alpha[s[0] - 'a'] = true;
        if(num == 0){
            prev = 1;
            nums.push_back(1);
        }
        for(int i = 1 ; i < s.length() ; i ++){
            if(alpha[s[i] - 'a'])
                num --;
            else{
                alpha[s[i] - 'a'] = true;
                num += (mp[s[i]] - 1);
            }
            if(num == 0){
                nums.push_back(i + 1 - prev);
                prev = i + 1;
            }
        }
        return nums;
    }
};


// A more efficient method
// 不需要那么多空间，只需要用一个大小为26的数组记录某个字符最后出现的位置即可。
// 维护一个变量 "一个字符串中某字符出现的最后位置"，
// 比如字符串"abcab":
//     刚开始最后位置置为3，因为a最后出现在3，但遍历到下一个b时这个变量就会被置为4因为b最后出现的位置在4
// 当我们遍历到的位置 == 维护的这个变量的值时就说明我们找到了一个字符串，此字符串中的字符均已出现完毕
class Solution2 {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        vector<int> ans;
        for(int i = 0 ; i < s.length() ; i ++){
            last[s[i] - 'a'] = i;
        }
        int end = -1;
        int prev = 0;
        for(int i = 0 ; i < s.length() ; i ++){
            end = max(end, last[s[i] - 'a']);
            if(end == i){
                ans.push_back(i + 1 - prev);
                prev = i + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution2 s;
    s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}