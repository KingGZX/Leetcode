/*
Q540
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

示例 1:
输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:
输入: nums =  [3,3,7,7,10,11,11]
输出: 10
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 二分思路：
    // 在"单独数"左边的有偶数个数字，又因为下标是从0开始的，所以单独数的下标一定是偶数
    // 而其余满足偶数下标的数都会符合 nums[i] = nums[i + 1]  (相当于是成对出现的数的第一个数)
    // 所以我们把二分中点调整至偶数下标
    // 假如满足了 nums[mid] = nums[mid + 1]，则单独数不会在左边，因为左边有偶数个数，所以把左边界调到mid + 2
    // 假如不满足，则单独数必在左边(一定是前面有一个单独数的干扰才会影响规律的正确性)，所以把右边界调整到mid。
    // 正因为有最开始的单独数左边
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            mid -= mid&1;               // 技巧性写法，因为mid为奇数时与结果为1，会被调整为偶数。 偶数与结果为0。
            if(nums[mid] == nums[mid + 1]){
                left = mid + 2;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }

    // 以例1为范式：
    // 1. mid = 4，mid[4] = 3 != 4 = mid[5]   所以 right = 4
    // 2. mid = 2，mid[2] = 2 != 3 = mid[3]   所以 right = 2
    // 3. mid = 1，mid[1] = 1 != 2 = mid[2]   所以 right = 1
    // 4. mid = 0，mid[0] = 1 = 1 = mid[1]    所以 left = 2
    // 5. left = 2 > 1 = right 所以退出循环
};

int main(){
    return 0;
}