/*
 * @author: Zhexuan Gu
 * @Date: 2023-03-11 13:08:40
 * @LastEditTime: 2023-03-11 20:38:39
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/inverse_pairs.cpp
 * @Description: Please implement
 */

/*
剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。


示例 1:

输入: [7,5,6,4]
输出: 5
*/


#include <iostream>
#include <vector>
using namespace std;


// 最简单的当然是暴力法 O(n^2), 但数组长度最大为 50000, 显然这个算法并不合理
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // deque<int> deq;
        int ans = 0;
        int ptr = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            for(int j = i + 1 ; j < nums.size() ; j ++){
                if(nums[i] > nums[j])
                    ans ++;
            }
        }
        return ans;
    }
};


/*
正确思路应该是 用归并排序
图解可见自己的pdf
*/

class Solution2 {
public:
    int ans = 0;
    void merge(vector<int>& nums, int left, int middile, int right){
        int i = left, j = middile + 1;
        vector<int> temp;
        while(i <= middile && j <= right){
            if(nums[i] > nums[j]){
                ans += (right - j + 1);
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i <= middile) temp.push_back(nums[i++]);
        while(j <= right) temp.push_back(nums[j++]);
        for(int i = 0 ; i < temp.size() ; i ++){
            nums[i + left] = temp[i];
        }
    }
    void mergesort(vector<int>& nums, int left, int right) {
        if(right > left){
            int middle = (left + right) >> 1;
            mergesort(nums, left, middle);
            mergesort(nums, middle + 1, right);
            merge(nums, left, middle, right);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return ans;
    }
};