/*
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，
而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 
示例：

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

*/

#include <iostream>
#include <vector>
using namespace std;


/*
此解的思路还是比较容易想到的：
    DFS辅助函数用于搜索，要确保位置合法的情况下且下一个要流动的位置的高度不高于自己
    用一个checked数组来记录某些位置是否已经被遍历到过。否则：
        从当前位置A找到一个高度齐平的位置B，递归进入那个位置B，如果没有checked记录，B又会回到A，最后爆栈
    
    此写法最后只能击败不到10%的人，这个算法最大的缺点就是DFS是一个无目标的深搜，我们不知道某条路径最后的结果，
    而且这条路径可能非常长！

    其实我们反过来想想就会发现有一种更优的解法，也算是“剪枝”的一种思想了。
    在Solution2给出
*/
class Solution {
public:
    bool **checked;
    bool DFS(vector<vector<int>>& heights, int i, int j, bool* Traverse[], int r_tar, int c_tar){   // i: row  j: col    tar means target
        if(Traverse[i][j]) return true;
        if(i == r_tar || j == c_tar){
            Traverse[i][j] = true;
            return true;
        }
        int row = heights.size();
        int col = heights[0].size();
        if(i - 1 >= 0 && heights[i][j] >= heights[i - 1][j] && !Traverse[i][j]){
            if(!checked[i - 1][j]){
                checked[i - 1][j] = true;
                Traverse[i][j] = DFS(heights, i - 1, j, Traverse, r_tar, c_tar);
                checked[i - 1][j] = false;
            }
        }
        if(i + 1 < row && heights[i][j] >= heights[i + 1][j] && !Traverse[i][j]){
            if(!checked[i + 1][j]){
                checked[i + 1][j] = true;
                Traverse[i][j] = DFS(heights, i + 1, j, Traverse, r_tar, c_tar);
                checked[i + 1][j] = false;
            }
        }
        if(j - 1 >= 0 && heights[i][j] >= heights[i][j - 1] && !Traverse[i][j]){
            if(!checked[i][j - 1]){
                checked[i][j - 1] = true;
                Traverse[i][j] = DFS(heights, i, j - 1, Traverse, r_tar, c_tar);
                checked[i][j - 1] = false;
            }
        }
        if(j + 1 < col && heights[i][j] >= heights[i][j + 1] && !Traverse[i][j]){
            if(!checked[i][j + 1]){
                checked[i][j + 1] = true;
                Traverse[i][j] = DFS(heights, i, j + 1, Traverse, r_tar, c_tar);
                checked[i][j + 1] = false;
            }
        }
        return Traverse[i][j];
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();
        bool** Atlantic = new bool* [row];
        bool** Pacific = new bool * [row];
        checked = new bool *[row];
        for(int i = 0 ; i < row ; i ++){
            Atlantic[i] = new bool[col];
            Pacific[i] = new bool [col];
            checked[i] = new bool[col];
            for(int j = 0 ; j < col ; j ++){
                Atlantic[i][j] = false;
                Pacific[i][j] = false;
                checked[i][j] = false;
            }
        }
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                checked[i][j] = true;
                bool At = DFS(heights, i, j, Atlantic, row - 1, col - 1);
                bool Pa = DFS(heights, i, j, Pacific, 0, 0);
                if(At && Pa){
                    vector<int> temp{i, j};
                    ans.push_back(temp);
                }
                checked[i][j] = false;
            }
        }
        for (int i = 0; i < row; i ++){
            delete[] Atlantic[i];
            delete[] Pacific[i];
            delete[] checked[i];
        }
        delete[] checked;
        delete[] Atlantic;
        delete[] Pacific;
        return ans;
    }
};

/*
这种逆向思维可以帮助我们击败80%的人
    我们从可以到达Pacific or Atlantic的点出发，寻找比自己高的点，这些点一定可以流入某个洋
    这样帮助减少了大量的无效深度搜索，减少了无用递归次数。
*/
class Solution2{
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    void DFS(vector<vector<int>>& heights, int r, int c, bool* Traverse[], int row, int col){
        if(Traverse[r][c]) return;
        Traverse[r][c] = true;
        for(int i = 0 ; i < 4 ; i ++){
            int x = r + directions[i];
            int y = c + directions[i + 1];
            if(x >= 0 && x < row && y >= 0 && y < col && heights[x][y] >= heights[r][c]){
                DFS(heights, x, y, Traverse, row, col);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();
        bool** Atlantic = new bool* [row];
        bool** Pacific = new bool * [row];
        for(int i = 0 ; i < row ; i ++){
            Atlantic[i] = new bool[col];
            Pacific[i] = new bool [col];
            for(int j = 0 ; j < col ; j ++){
                Atlantic[i][j] = false;
                Pacific[i][j] = false;
            }
        }
        for(int i = 0 ; i < row ; i ++){
            DFS(heights, i, 0, Atlantic, row, col);
            DFS(heights, i, col - 1, Pacific, row, col);
        }
        for(int i = 0 ; i < col ; i ++){
            DFS(heights, 0, i, Atlantic, row, col);
            DFS(heights, row - 1, i, Pacific, row, col);
        }
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(Atlantic[i][j] && Pacific[i][j]){
                    vector<int> temp{i, j};
                    ans.push_back(temp);
                }
            }
        }
        for (int i = 0; i < row; i ++){
            delete[] Atlantic[i];
            delete[] Pacific[i];
        }
        delete[] Atlantic;
        delete[] Pacific;
        return ans;
    }
};

int main(){
    Solution2 s;
    vector<vector<int>> vec{{1, 2, 2, 3, 5},
                            {3, 2, 3, 4, 4},
                            {2, 4, 5, 3, 1},
                            {6, 7, 1, 4, 5},
                            {5, 1, 1, 2, 4}};
    s.pacificAtlantic(vec);
    return 0;
}