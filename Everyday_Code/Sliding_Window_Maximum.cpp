/*
Q239
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        // 先把deq初始化，这之后每次加一个元素即可。
        for(int i = 0 ; i < k ; i ++){
             if(deq.empty())
                    deq.push_front(i);
            else{
                if(nums[i] <= nums[deq.front()]){
                    while(nums[i] > nums[deq.back()]){
                        deq.pop_back();
                    }
                    deq.push_back(i);
                }
                else{
                    deq.clear();
                    deq.push_front(i);
                }
            }
        }
        ans.push_back(nums[deq.front()]);
        int left = 1, right = k;
        while(right < nums.size()){
            if(deq.front() < left){
                deq.pop_front();
            }
            if(nums[right] > nums[deq.front()]){
                deq.clear();
                deq.push_front(right);
            }
            else{
                while(nums[right] > nums[deq.back()]){
                        deq.pop_back();
                    }
                deq.push_back(i);
            }
            ans.push_back(nums[deq.front()]);
            left ++;
            right ++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> vec{1, 3, 1, 2, 0, 5};
    s.maxSlidingWindow(vec, 3);
    return 0;
}