/*
Q46
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]

*/

#include <iostream>
#include <vector>
using namespace std;

/*
下列解法在特定网络情况下可以击败100%的人。
思路很容易：
    首先回溯法我们可以视为是“DFS”深度优先搜索的一种特殊情况，即我们对递归返回后要做一些处理。
    此题中设置traverse判定某个位置的值是否已被采用，temp是装ans里一个特定元素的临时容器，ans就是最后返回值。
    思路：
        主要看backtrack的处理方法。
        递归总是很难用语言描述清楚的，但用模拟的方法一步步看下去会是一种很好的办法。
        第一轮递归到结束就是按原先的顺序完全进入temp罢了，然后递归返回将最后一个数弹出并置为未访问状态，循环结束
        递归再次返回，倒数第二个数弹出同样被置为未访问状态，但此处循环还能继续，会访问最后一个数，然后就会被装入，
        紧接着进入递归并装入倒数第二个数......
        然后回退到最开始，将第一个数弹出，然后装入第二个数，开始以第二个数打头的排列组合，就是这样······
        照此方法，最后就能实现全模拟。
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, vector<bool>& traverse){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i ++){
            if(!traverse[i]){
                temp.push_back(nums[i]);
                traverse[i] =  true;
                backtrack(nums, traverse);
                traverse[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> traverse(nums.size(), false);
        backtrack(nums, traverse);
        return ans;
    }
};

int main(){

    return 0;
}