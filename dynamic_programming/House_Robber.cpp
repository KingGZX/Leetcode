/*
Q198
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

 

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    题意已经非常明确了，直接思考转移方程的情况：
        当前这家如果偷，那么从前前家转移过来，因为相邻的会报警 dp[i] = dp[i - 2] + nums[i]
        如果当前这家不偷则直接继承上一家偷完的值 dp[i] = dp[i - 1]
        两者取大 所以最后的转移方程就是   dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
    */
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int prev1 = nums[0], prev2 = max(nums[1], nums[0]);
        int ans = prev2;    // 这种形式的初始化以防止 size = 2的情况下，for循环不执行，ans初值错误。
        for(int i = 2 ; i < nums.size() ; i ++){
            ans = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};

int main(){
    return 0;
}