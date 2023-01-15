/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-15 19:41:12
 * @LastEditTime: 2023-01-15 19:50:37
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/min_length_subarray_exceed_target.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int cur = 0;
        int window_front = 0, window_end = 0;
        while(window_front < nums.size() && window_end < nums.size() && ans > 1){
            cur += nums[window_end++];
            if(cur >= target){
                ans = min(ans, window_end - window_front);
                cur -= nums[window_front ++];
                cur -= nums[--window_end];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

/*
用一个简单例子体现我的 滑动窗口的思想
示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

初始化 window_front = window_end = 0， 初始化我们求的和为0，初始化长度为一个INT_MAX

1. 遍历第一个值，加上后cur = 2，window_end = 1，无事发生
2. 遍历第二个值，加上后cur = 5，window_end = 2，无事发生
3. 遍历第三个值，加上后cur = 6，window_end = 3，无事发生
4. 遍历第四个值，加上后cur = 8，window_end = 4，此时：
                                                更新当前最短长度为4 （window_end - window_front）
                                                且要去滑动窗口的头，所以 window_front ++ ，且要把这个滑出去的值从cur中减去
                                                ------------最后一步就是trick了!!!------------
                                                cur -= nums[--window_end];
                                                其实就是我们得考虑这么一种情况，现在的cur是8，那假如我们移出去的头是1呢？
                                                ----也就是说我们下一轮对当前这个刚移除window头的子数组还得进行一次判断----
                                                那么我们就先把window_end移回到3，并减去对应值，循环的下一轮这个值又会被加上，不就相当于再次进行了上述的判断吗！

*/

int main(){
    return 0;
}