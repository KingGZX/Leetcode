/*
Q213
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，
这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 3：
输入：nums = [1,2,3]
输出：3
*/

#include <iostream>
using namespace std;

class Solution {
public:
    //两个dp数组，一个用于偷第一家时使用，另一个用于不偷第一家使用
    // 最后就返回第一个的倒数第二家位置偷得钱和第二个的倒数第一家位置偷得钱较大值即可
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int sz = nums.size();
        vector<int> dp1(sz, 0);
        vector<int> dp2(sz, 0);
        dp1[0] = nums[0], dp2[1] = nums[1];
        for(int i = 1 ; i < sz - 1 ; i ++){
            if(i - 2 < 0){
                dp1[i] = max(nums[i], dp1[i - 1]);
            }
            else{
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
        }
        for(int i = 2 ; i < sz ; i ++){
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp2[sz - 1], dp1[sz - 2]);
    }
};

int main(){
    return 0;
}