/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-19 12:50:02
 * @LastEditTime: 2023-01-19 15:13:42
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/three_num_in_array_sum_0.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
 

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int ptr = 0;
        while(ptr < nums.size()){
            int cur = nums[ptr];
            vector<int> temp;
            temp.resize(3);
            int left = ptr + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + cur;
                if(sum == 0){
                    temp[0] = cur, temp[1] = nums[left], temp[2] = nums[right];
                    ans.push_back(temp);
                    int k = nums[left];
                    while(left < right && nums[left] == k) left ++;
                }
                else if(sum > 0){
                    int k = nums[right];
                    while(left < right && nums[right] == k) right --;
                }
                else{
                    int k = nums[left];
                    while(left < right && nums[left] == k) left ++;
                }
            }
            while(ptr < nums.size() && nums[ptr] == cur) ptr++; // avoid repeating
        }
        return ans;
    }
};

/*
思路：用到的是双指针的思想
先排序一下才可以使用双指针

由于要选三个数，所以采用的是确定第一个数，到第一个数后面的区间使用双指针搜索所有可行解
由于要避免重复，所以 “while(ptr < nums.size() && nums[ptr] == cur) ptr++; // avoid repeating” 用于避免第一个数的重复
第一个数的指针是ptr，当前值是cur，所以确定的数的选择应该保持不同

第二第三个数也就是双指针区间自然也会产生重复，用到的是同样的思路，看代码便知，(普通情况下可能直接left++ 或者 right-- 即可)

双指针具体思想：
比如给定一个数组 1 2 3 4 5 6 7   ---------(已排序的)
我们要找到其中两个数和为5的所有组合

确定left = 0， right = 6 （数组上下界）
现在 nums[left] + nums[right] = 1 + 7 = 8，太大，由于数组是有序的，自然要做的就是把偏大的数减小，所以把右指针往左移
反之，则移动左指针

我们找到第一组合适的数 [1, 4]后并不能停止，因为left = 0， right = 3，left < right，循环仍会继续
此时可以任意选择左指针移动 or 右指针移动，在这样的策略下，另一组 [2, 3]和为5也能被顺利找到！
*/

int main(){
    return 0;
}