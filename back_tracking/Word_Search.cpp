/*
Q79
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。


示例 1：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
示例 3：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int row;
    int col;
    bool ans = false;
    vector<int> direction{-1, 0, 1, 0, -1};
    void backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& t, int r, int c, int ptr){
        if(ptr == word.size()){
            ans = true;
            return ;
        }
        for(int i = 0 ; i < 4 ; i ++){
            int x = r + direction[i];
            int y = c + direction[i + 1];
            if(x >= 0 && x < row && y >= 0 && y < col && board[x][y] == word[ptr] && !t[x][y]){
                t[x][y] = true;
                backtrack(board, word, t, x, y, ptr + 1);
                if(ans) return;
                t[x][y] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> traverse(row, vector<bool>(col, false));
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(board[i][j] == word[0]){
                    traverse[i][j] = true;
                    int ptr = 1;
                    backtrack(board, word, traverse, i, j, ptr);
                    if(ans) return true;
                    traverse[i][j] = false;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<char>> vec{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    s.exist(vec, "SEE");
    return 0;
}