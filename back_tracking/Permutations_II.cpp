/*
Q47
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;

    void dfs(vector<bool>& visited, vector<int>& nums){
        if(vec.size() == nums.size()){
            ans.push_back(vec);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i ++){
            if(i - 1 >= 0 && !visited[i - 1] && nums[i] == nums[i - 1])
                continue;
            if(!visited[i]){
                visited[i] = true;
                vec.push_back(nums[i]);
                dfs(visited, nums);
                vec.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int item1, int item2){
            return item1 > item2;
        });
        int sz = nums.size();
        vector<bool> visited(sz, false);
        dfs(visited, nums);
        return ans;
    }
};


int main(){
    return 0;
}