/*
Q34
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 实际上我并没有完全符合logn时间复杂度
    // 利用二分法在logn时间复杂度内第一次找到target出现的位置
    // 从该位置向左向右延展找到边界
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int start = 0, end = nums.size() - 1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target){
                if(left == right) return {left, left};
                else{
                    for(int i = mid - 1; i >= 0 ; i --){
                        if(nums[i] != target){
                            start = i + 1;
                            break;
                        }
                    }
                    for(int i = mid + 1 ; i <= end ; i ++){
                        if(nums[i] != target){
                            end = i - 1;
                            break;
                        }
                    }
                    return {start, end};
                }
            }
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return {-1, -1};
    }


    int Lowerbound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        // 因为我们要找的target出现的下界，思想就是:
        // 如果二分搜出来的数 >= target，就把上界压缩下来即  right = mid
        // 否则的话，把下界提升上去, 即 left = mid + 1
        // 当 left = right 时停止搜索，返回
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] >= target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }

    int Higherbound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        // 看似和求lowerbound一致，其实不然
        // 注意我们这里缺失了一个 " = "的条件
        // 就是说，即使我们二分找到了target，仍旧把下界往上提
        // 这样就能确保最后我们的left = right的同时，两者刚好落在最后一次出现的右边一个位置
        // 因此回到主函数的时候需要做一个  "-1"  处理
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<int> vec{5, 7, 7, 8, 8, 10};
    s.Lowerbound(vec, 8);
    return 0;
}