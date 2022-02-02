/*
Q416
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。


示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // DP思路
    // 如果nums数组和不是偶数，显然不能求解
    // 将此问题想象成 0 - 1 背包问题， 背包容量是 sum / 2， 且可以取的物体并没有体积限制这一条件
    // dp数组是一个bool型数组
    // 用dp[i] = true 表示某一容量i(target 目标值)下，是否存在刚好填充这个容量的一些物品(数组中的数)
    // 对于第i个位置的数，目标值为j时，动态转移方程即：
    // dp[i] = dp[i] || dp[j - nums[i]]
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int sz = sum / 2 + 1;
        int n = sz - 1;
        vector<bool> dp(sz);
        dp[0] = true;
        for(int i = 0 ; i < nums.size() ; i ++){
            for(int j = n ; j >= nums[i] ; j --){
                dp[j] = dp[j] || dp[j - nums[i]];
                if(dp[n]) break;
            } 
            if(dp[n]) break;
        }
        return dp[n];
    }
};

int main(){
    vector<int> vec{3, 3, 3, 4, 5};
    Solution s;
    s.canPartition(vec);
    return 0;
}