/*
Q744

给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 

示例 1：

输入: letters = ["c", "f", "j"]，target = "a"
输出: "c"
示例 2:

输入: letters = ["c","f","j"], target = "c"
输出: "f"
示例 3:

输入: letters = ["c","f","j"], target = "d"
输出: "f"
*/

#include <iostream>
#include <vector>
using namespace std;

// 用二分法效率反倒变低，主要原因怀疑是题目给出的样本案例长度太小

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = ' ';
        int left = 0, right = letters.size() - 1;
        while(left <= right){
            int mid = ((right - left) >> 1) + left;
            if(letters[mid] > target){
                ans = letters[mid];
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        ans = ans == ' ' ? letters[0] : ans;
        return ans;
    }
};

int main(int argc, const char** argv) {
    return 0;
}