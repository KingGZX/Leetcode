/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-18 15:38:40
 * @LastEditTime: 2023-01-18 16:22:26
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/max_product_of_words.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，它们长度的乘积的最大值。
假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

示例 1:
输入: words = ["abcw","baz","foo","bar","fxyz","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "fxyz"。它们不包含相同字符，且长度的乘积最大。

示例 2:
输入: words = ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。

示例 3:
输入: words = ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。
*/

class Solution {
public:
    // version 1, 也能过，就是为每个单词开一个map记录自己的字符使用情况，这样一来可以避免对比两个单词是否有重复字符使用情况的 O(n^2) 时间复杂度
    /*
    int maxProduct(vector<string>& words) {
        int maxLen = 0;
        vector<map<char, bool>> vec;
        for(int i = 0 ; i < words.size() ; i ++){
            map<char, bool> mp;
            for(const char& ch : words[i]) mp[ch] = true;
            vec.emplace_back(mp);
        }
        for(int i = 0 ; i < words.size() ; i ++){
            int len = words[i].length();
            for(int j = i + 1 ; j < words.size() ; j ++){
                if(len * words[j].length() > maxLen){
                    bool flag = true;
                    for(const char& ch : words[i]){
                        if(vec[j][ch]){
                            flag = false;
                            break;
                        }
                    }
                    maxLen = flag == true ? len * words[j].length() : maxLen;
                }
            }
        }
        return maxLen;
    }
    */

   // 自己优化错方向了
   // 用到的仍旧是 bit operation技巧
   // 因为即使用hashtable ， 可以看见在判定两个string时仍要O(n)，但位运算可以优化到O(1)
   // 因为字符就26个，可以用26个bit来表示，两个做一下 ‘与’ 运算，不为0则代表着有重复字符
   int maxProduct(vector<string>& words) {
        int maxLen = 0;
        vector<int> bits(words.size(), 0);
        for(int i = 0 ; i < words.size() ; i ++){
            for(char ch : words[i]){
                bits[i] |= (1 << (ch - 'a'));
            }
        }
        for(int i = 0 ; i < words.size() ; i ++){
            int len = words[i].length();
            for(int j = i + 1 ; j < words.size() ; j ++){
                if(!(bits[i] & bits[j])){
                    maxLen = max(maxLen, len * int(words[j].length()));
                }
            }
        }
        return maxLen;
    }
};

int main(){
    vector<string> words{"abcw", "baz", "foo", "bar", "fxyz", "abcdef"};
    Solution s;
    s.maxProduct(words);
    return 0;
}