/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-20 22:58:23
 * @LastEditTime: 2023-01-20 23:05:16
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/occurrence_of_number_in_an_array.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。


示例 1：
输入：nums = [3,4,3,3]
输出：4

示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < sz ; i += 3){
            if((i + 2 < sz && nums[i] != nums[i + 2]) || i + 2 >= sz){
                ans = nums[i];
                break;
            }
        }   
        return ans;
    }
};

/*
思路：
    sort完之后，出现三次的数会连排
    所以唯一的trick就是在for循环里

    可以看见 i 的step为3 , nums[i + 2] == nums[i] 证明了就是三个数连排好的

    若 i + 2 越界了，同样证明了某个数出现次数不够次数

*/

int main(){
    return 0;
}