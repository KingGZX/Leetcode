/*
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。
你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

示例 1：


输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
            [0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],
            [0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],
            [0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],
            [0,0,0,0,0,0,0,1,1,0,0,0,0]]
输出：6
解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 写成下列形式的dfs并无法做优化，因为我们没有什么“剪枝策略”。
// 然后我们可以用“栈”来模拟深度优先搜索，在Solution2给出
class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid, int row, int col, bool* check[], int& area){
        check[row][col] = true;
        int r = grid.size();
        int c = grid[0].size();
        if(row - 1 >= 0 && grid[row - 1][col] == 1 && !check[row - 1][col]){
            area += 1;
            dfs(grid, row - 1, col, check, area);
        }
        if(row + 1 < r && grid[row + 1][col] == 1 && !check[row + 1][col]){
            area += 1;
            dfs(grid, row + 1, col, check, area);
        }
        if(col + 1 < c && grid[row][col + 1] == 1 && !check[row][col + 1]){
            area += 1;
            dfs(grid, row, col + 1, check, area);
        }
        if(col - 1 >= 0 && grid[row][col - 1] == 1 && !check[row][col - 1]){
            area += 1;
            dfs(grid, row, col - 1, check, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        bool ** check = new bool* [row];
        for(int i = 0 ; i < row ; i ++){
            check[i] = new bool [col];
            for(int j = 0 ; j < col ; j ++)
                check[i][j] = false;
        }
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(grid[i][j] && !check[i][j]){
                    int area = 1;
                    dfs(grid, i, j, check, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};

class Solution2{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int ans = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int x, y;
        int row = grid.size();
        int col = grid[0].size();
        stack<pair<int, int>> st;
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(grid[i][j]){
                    int area = 1;
                    st.push({i, j});
                    grid[i][j] = 0;
                    while(!st.empty()){
                        auto [r, c] = st.top();
                        st.pop();
                        for(int k = 0 ; k < 4 ; k ++){    // 模拟搜索的四个方向
                            x = r + direction[k], y = c + direction[k + 1];
                            if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y]){
                                grid[x][y] = 0;
                                area ++;
                                st.push({x, y});
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};



int main(){
    Solution s;
    vector<vector<int>> island =   {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                    {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                    {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                    {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                    {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                    {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                    {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    s.maxAreaOfIsland(island);
    int a = 0;
    return 0;
}