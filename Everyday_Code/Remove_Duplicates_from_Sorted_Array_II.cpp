#include <iostream>
#include <vector>
using namespace std;

/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

Example:
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。

输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int cur_num = nums[0];
        int cur_cnt = 1;
        int ptr = 1;
        int ans = 1;
        for(int i = 1 ; i < len ; i ++){
            // 如果出现次数 小于2，那就持续写入
            while(i < len && nums[i] == cur_num && cur_cnt < 2){
                nums[ptr++] = cur_num;
                cur_cnt ++;
                i ++;
                ans ++;
            }
            // 如果是因为i越界
            if(i >= len) break;
            // 如果是因为某个数出现次数超出了限制，那就一直找到下一个不同的数出现的位置
            if(cur_cnt >= 2){
                while(i < len && nums[i] == cur_num) i++;
                if(i >= len) break;
            }
            // 遇到新的数了
            cur_num = nums[i];
            nums[ptr++] = cur_num;
            cur_cnt = 1;
            ans ++;
        }
        return ans;
    }
};