/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-24 22:42:00
 * @LastEditTime: 2023-05-01 21:40:23
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/subarray_sum_k.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。

 

示例 1：
输入:nums = [1,1,1], k = 2
输出: 2
解释: 此题 [1,1] 与 [1,1] 为两种不同的情况

示例 2：
输入:nums = [1,2,3], k = 3
输出: 2
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 应该和three_num_in_array 那个题的 slide window 思路差不多
        int left = 0, right = 0;
        int sz = nums.size();
        int sum = 0;
        int num = 0;
        while(left <= right && right < sz){
            if(sum == k){
                sum -= nums[left++];
                num ++;
            }
            else if(sum < k){
                sum += nums[right++];
            }
            else{

            }
        }
        return num;
    }
};

int main(){
    return 0;
}