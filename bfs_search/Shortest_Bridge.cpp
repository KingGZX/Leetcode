/*
Q934
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）

示例 1：

输入：A = [[0,1],
          [1,0]]
输出：1
示例 2：

输入：A = [[0,1,0],
          [0,0,0],
          [0,0,1]]
输出：2
示例 3：

输入：A = [[1,1,1,1,1],
          [1,0,0,0,1],
          [1,0,1,0,1],
          [1,0,0,0,1],
          [1,1,1,1,1]]
输出：1

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    // 解题思路:
    // 先找到一个岛屿分量，然后利用广度优先搜索去找和另一岛屿的最近距离
    // 具体解法:
    // 先用暴搜搜到第一个岛屿的某个'1'(分量)，然后通过DFS将此岛屿内的所有分量置为'2'
    // 然后在搜索过程中将离岛最近的一层'0'的所有位置记录，对这些位置进行BFS，将那些'0'
    // 一轮BFS距离就加一，直至遍历到下一个'1'，即另一个岛屿的分量
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> points;
        bool temp = false;
        for(int i = 0 ; i < row ; i ++){
            if(temp) break;
            for(int j = 0 ; j < col ; j ++){
                if(grid[i][j] == 1){
                    DFS(grid, points, i, j);
                    temp = true;
                    break;
                }
            }
        }
        int path = 0;
        while(!points.empty()){
            int sz = points.size();
            path += 1;
            while(sz --){
                auto [r, c] = points.front();
                grid[r][c] = 2;
                for(int i = 0 ; i < 4 ; i ++){
                    int x = r + direction[i];
                    int y = c + direction[i + 1];
                    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] != 2){
                        if(grid[x][y] == 1)
                            return path;
                        else{
                            grid[x][y] = 2;
                            points.push({x, y});
                        }
                    }
                }
                points.pop();
            }
        }
        return 1;
    }

    void DFS(vector<vector<int>>& grid, queue<pair<int, int>>& points, int i, int j){
        if(grid[i][j] == 1){
            grid[i][j] = 2;
        }
        else if(grid[i][j] == 0){
            points.push({i, j});
            return ;
        }
        for(int k = 0 ; k < 4 ; k ++){
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 2){
                DFS(grid, points, x, y);
            }
        }
    }
};

int main(){
    vector<vector<int>> grid{{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    Solution s;
    s.shortestBridge(grid);
    return 0;
}