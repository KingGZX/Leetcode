/*
Q53
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 这其实也是一道典型的分治题
    int maxSubArray(vector<int>& nums) {
        // 用 dp[i][0]表示第i个元素选中时的最大和
        // 用 dp[i][1]表示第i个元素不选时的最大和
        int sz = nums.size();
        vector<vector<int>> dp(sz, vector<int>(2, 0));
        // 首元素即使不选中时我们也将其置为nums[0]，这是为了避免容器中均为负数，最后一个不选结果为0报错的情况
        ddp[0][0] = dp[0][1] = nums[0];
        for(int i = 1 ; i < sz ; i ++){
            // 选中时，我们要门就是从前面连续选中的最大和继承，要么就是自己作为头来继承
            dp[i][0] = max(dp[i - 1][0], 0) + nums[i];
            // 不选中时，就从前面那个元素的两种情况取大即可
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[sz - 1][0], dp[sz - 1][1]);
    }

    // 做常数级空间优化
    int maxSubArray(vector<int>& nums) {
        // 用 dp[i][0]表示第i个元素选中时的最大和
        // 用 dp[i][1]表示第i个元素不选时的最大和
        // 首元素即使不选中时我们也将其置为nums[0]，这是为了避免容器中均为负数，最后一个不选结果为0报错的情况
        int choose, notchoose;
        choose = notchoose = nums[0];
        for(int i = 1 ; i < nums.size() ; i ++){
            // 先保留choose，因为我们在下一步要对choose进行修改
            int prev = choose;
            // 选中时，我们要门就是从前面连续选中的最大和继承，要么就是自己作为头来继承
            choose = max(choose, 0) + nums[i];
            // 不选中时，就从前面那个元素的两种情况取大即可
            notchoose = max(prev, notchoose);
        }
        return max(choose, notchoose);
    }

    int maxSubArray(vector<int>& nums) {
        // 最后做一次概念上的优化
        // 我们简化区分"选/不选"的概念
        // 用变量pre表示到前一个元素为止的最大和
        // 用maxAns始终保证当前最大值
        int pre = 0, maxAns = nums[0];
        for(int i = 0 ; i < nums.size() ; i ++){
            // 更新pre
            // 对于当前这个元素我们不再有"选"与"不选"的概念
            // 我们转换为与不与前面的值结合
            pre = max(nums[i], pre + nums[i]);
            maxAns = max(pre, maxAns);
        }
        return maxAns;
    }
};

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    s.maxSubArray(nums);
    return 0;
}