/*
Q542

给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

输入：mat = [[0,0,0],
            [0,1,0],
            [0,0,0]]

输出：[[0,0,0],
      [0,1,0],
      [0,0,0]]


示例 2：
输入：mat = [[0,0,0],
            [0,1,0],
            [1,1,1]]

输出：[[0,0,0],
      [0,1,0],
      [1,2,1]]

*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // 这里用到了暴力dfs的思想
    /*
    先找出所有原先的0
    从这些0出发找到那些距离为'1'的点，接下来就会从距离为1的出发，将下一波更新为距离2
    只有更新某点的最短距离时才会把这个点又装入队列，因为只有自己的最短距离更新了从自己出发的最短距离才有机会更新
    */
    vector<int> directions{-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, INT32_MAX));
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        queue<pair<int, int>> temp;
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(mat[i][j] == 0){
                    visit[i][j] = true;
                    ans[i][j] = 0;
                    temp.push({i, j});
                }
            }
        }
        while(!temp.empty()){
            auto [r, c] = temp.front();
            temp.pop();
            for(int i = 0 ; i < 4 ; i ++){
                int x = r + directions[i];
                int y = c + directions[i + 1];
                if(x >= 0 && x < row && y >= 0 && y < col && !visit[x][y]){
                    ans[x][y] = ans[r][c] + 1;
                    temp.push({x, y});
                    visit[x][y] = true;
                }
            }
        }
        return ans; 
    }
    // 显然dfs是偏暴力的，没有所谓的"最优子结构"，"利用已有问题的解"等思想
    // 明明可能某个点A的距离2是从其边上的另一个点B引申过来的，但这个距离为2的点A却偏偏dfs还要再去问一遍B点
    /*
        这题的DP有点怪，但又和"贪心算法中"--"Assign Cookies"很像，我们要对DP进行分解。
        原因很简单，我们第一遍从头到尾遍历或许有一些格子里的'1'周围都是'1'，那么其最短距离在此时并无法确定
        但我们还可以做第二遍操作，即从尾到头进行遍历。

        第一遍从左上角到右下角，每一个点根据其 左边和上边的 点进行更新距离
        第二遍从右下角到左上角，每一个点根据其 右边和下面的 点进行更新距离

        第一遍可以确保0的右下方的点全都被更新 但左上方或许没有被更新到
        因为一旦某些点的右或上存在了0，自己的距离就会被更新为1，随之后面的就会产生2、3或者有新的1等。

        但第二遍可以确保左上方的点也全部可以根据当前最短距离进行更新
        比如:
            1 1 1
            0 1 1
            0 0 1
        我们第一遍确实可以改成   
            2e4 2e4 2e4
            0   1   2
            0   0   1
        但正如我们说的位于0的左和上的位置修改不到，所以第二遍我们利用第一遍的局部最优结果来更新剩余位置
            1   2   3
            0   1   2
            0   0   1
    */
    
    vector<vector<int>> updateMatrix2(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 2e4));   // 设为20000是因为mat的最大边长是1e4
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(mat[i][j] == 0)
                    ans[i][j] = 0;
            }
        }

        // 第一遍dp
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(i - 1 >= 0){
                    ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                }
                if(j - 1 >= 0){
                    ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                }
            }
        }

        // 第二遍dp
        for(int i = row - 1 ; i >= 0 ; i --){
            for(int j = col - 1 ; j >= 0 ; j --){
                if(i + 1 < row){
                    ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                }
                if(j + 1 < col){
                    ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    s.updateMatrix(vec);
    return 0;
}