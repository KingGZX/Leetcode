/*
Q64
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

输入：grid = [[1,3,1],
             [1,5,1],
             [4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：

输入：grid = [[1,2,3],
             [4,5,6]]
输出：12    
路径  1->2->3->6
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    这一题的转移方程非常好找
    对于某一个位置，我们可以从其上方走下来亦或是从其左边走过来，我们要求最小的，所以有：
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
    要注意的就是越界问题，所以我预先写了两个循环处理边界问题
    */
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 1 ; i < grid.size() ; i ++){
            grid[i][0] += grid[i - 1][0];
        }
        for(int i = 1 ; i < grid[0].size() ; i ++){
            grid[0][i] += grid[0][i - 1];
        }
        for(int i = 1 ; i < grid.size() ; i ++){
            for(int j = 1 ; j < grid[0].size() ; j ++){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }

    // 空间压缩解法  ---------------》 上面的解法在原数组上改动，虽然没有额外空间，但显然修改原数组并不是好办法
    int minPathSum2(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> dp(col, 0);
        // dp[j] 一开始是自己上一行的值
        // dp[j - 1] 就是自己前一列的值
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(i == 0 && j == 0)
                    dp[j] = grid[0][0];
                else if(i == 0)         // 相当于我们一开始一直在更新第一行，就是前一个dp加上本身值
                    dp[j] = dp[j - 1] + grid[0][j];
                else if(j == 0)         // 相当于更新第一列值，就是本列的上一个值加上本身
                    dp[j] = dp[j] + grid[i][0];
                else                    
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[col - 1];
    }
};

int main(){
    return 0;
}