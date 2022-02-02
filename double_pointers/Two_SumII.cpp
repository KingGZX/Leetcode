/*
Q167
给定一个已按照 非递减顺序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

*****************
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 非递减顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案
****************
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);    // initialize the answer vector
        int ptr1 = 0;
        int ptr2 = numbers.size() - 1;
        while(ptr2 > ptr1){
            int temp_sum = numbers[ptr1] + numbers[ptr2];
            if(temp_sum == target){
                ans[0] = ptr1;
                ans[1] = ptr2;
                return ans;
            }
            else if(temp_sum < target){
                // make the sum bigger, so shift pointerI to increase the sum
                ptr1 ++;
            }
            else{
                // shift pointerII to decrease the sum
                ptr2 --;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}