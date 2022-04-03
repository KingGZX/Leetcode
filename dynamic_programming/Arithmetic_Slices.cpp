/*
Q413
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。

 

示例 1：

输入：nums = [1,2,3,4]
输出：3
解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1, 2, 3, 4] 自身。
示例 2：

输入：nums = [1]
输出：0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    用dp[i]来表示nums数组中到第i个位置为止的总共等差数列的量
    用变量diff保持前一对数的差值
    用变量len维护最近的等差数列的长度
    转移方程
        如果当前这对数的差值不等于diff，则 dp[i] = dp[i - 1]，同时更新diff，更新len
        如果等于diff，则更新len，且dp[i] = dp[i - 1] + len - 2
    
    思路解析：
        不等于diff很好想，我们复制前面的最大的等差数列量，同时要更新差值因为后续要按这个新差值寻找，len重新归为2
        等于的情况下，为什么加上 len - 2是要点：
            思考  1 2 3 4     到3的时候，len是3，dp[3] = dp[2] + 3 - 2 = 1
            到4的时候    len是4，dp[4] = dp[3] + 4 - 2 = 3
        这其实本质上还是数学上的归纳总结罢了：
            从 1 2 3 4  ----》    1 2 3 4 5 多出来的等差数列有  "1, 2, 3, 4, 5" , "2, 3, 4, 5", "3, 4, 5"
            也是len - 2 即 5 - 2。

        所以len - 2的意思，就是从 第一个位置开始  到  len - 2 那个位置，这些位置到最后位置的等差数列都是多出来的！
        对照上面，1 2 3 4 5，就是 从第一个位置 "1" 到 len - 2那个位置"3" ， 这些位置到最后位置"5"，的等差数列都是
        多出来的。  那不就是下标  0 ~ len - 3 往前面的子结果一加就行， 0 ~ len - 3 共len - 2个数。
    */
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        vector<int> dp(nums.size());
        int diff = nums[1] - nums[0], len = 2;
        for(int i = 2; i < nums.size() ; i ++){
            if(nums[i] - nums[i - 1] != diff){
                diff = nums[i] - nums[i - 1];
                len = 2;
                dp[i] = dp[i - 1];
            }
            else{
                ++ len;
                dp[i] = dp[i - 1] + len - 2;
            }
        }
        return *(dp.end() - 1);
    }

    // 对上述代码的改进，仍旧是抛弃数组的思想：
    int numberOfArithmeticSlices2(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int ans = 0, prev = 0;
        int diff = nums[1] - nums[0], len = 2;
        for(int i = 2; i < nums.size() ; i ++){
            if(nums[i] - nums[i - 1] != diff){
                diff = nums[i] - nums[i - 1];
                len = 2;
                // ans = prev;
            }
            else{
                ++ len;
                ans = prev + len - 2;
                prev = ans;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}