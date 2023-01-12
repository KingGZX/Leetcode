/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-12 09:22:06
 * @LastEditTime: 2023-01-12 09:50:03
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/path_in_matrix.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

 

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
*/


// 思路较为简单,就是回溯啦,从某个点出发,若是一个方向不行,就回到出发点尝试另一方向
class Solution {
private:
    int row, col;
    vector<pair<int, int>> directions {pair<int, int>(-1, 0),           // up
                                        pair<int, int>(1, 0),           // down
                                        pair<int, int>(0, 1),           // right
                                        pair<int, int>(0, -1)};         // left
    vector<vector<bool>> visited;
public:
    bool backtrack(vector<vector<char>>& board, string word, int ptr, string cur, int x, int y){
        if(word == cur) return true;
        for(int i = 0 ; i < 4 ; i ++){
            int newx = x + directions[i].first;
            int newy = y + directions[i].second;
            if(newx >= 0 && newx < row && newy >= 0 && newy < col){
                if(board[newx][newy] == word[ptr] && !visited[newx][newy]){
                    visited[newx][newy] = true;
                    bool ans = backtrack(board, word, ptr + 1, cur + board[newx][newy], newx, newy);
                    if(ans) return true;
                    visited[newx][newy] = false;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> temp(row, vector<bool>(col, false));
        visited = temp;
        int ptr = 0;
        string cur = "";
        cur += word[ptr];
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(board[i][j] == word[ptr]){
                    visited[i][j] = true;
                    bool ans = backtrack(board, word, ptr + 1, cur, i, j);
                    if(ans) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main(){
    return 0;
}