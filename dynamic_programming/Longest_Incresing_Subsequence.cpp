/*
Q300
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // dp[i]表示第i个数为止(必须包括第i个数本身的)的最长严格递增子序列
    // 我们就去前面的dp数组里找，更新出把自己包括进去的最大值
    // 显然这个解法是O(n²)的
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1 ; i < n ; i ++){
            for(int j = 0 ; j < i ; j ++){
                if(nums[i] > nums[j] && dp[j] >= dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // 解法二是利用"贪心" + "二分" 以达到O(nlog(n))的时间复杂度
    // 步骤就是遍历nums数组，同时另外提前开辟好一个数组
    // 将遍历到的数值插入到新数组中，利用二分法插入。
    // 如果比最大元素还要大的话就插入到最后   (相当于更新了最长的长度)
    // 否则根据二分，查找到位置后，比如在 元素  (a, b)之间，那就把b更新为当前遍历着的这个元素
    // 因为做这样的更新有更大可能找到更长的递增数组。 当然如果此值无效，那么最长长度也不会改变，仍旧是正确的
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        int len = 1;   // 维护dp的长度
        for(int i = 1 ; i < nums.size() ; i ++){
            if(nums[i] > dp[len]){
                dp[++len] = nums[i];
            }
            else{
                int l = 1, r = len;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(nums[i] == dp[mid]) break;   // we don't need to modify anything
                    else if(nums[i] > dp[mid]) l = mid + 1;
                    else r = mid - 1;
                }
                if(nums[i] < dp[l])
                    dp[l] = nums[i];
            }
        }
        return len;
    }
};



int main(){
    return 0;
}