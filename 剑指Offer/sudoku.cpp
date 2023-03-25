/*
 * @author: Zhexuan Gu
 * @Date: 2023-03-25 23:45:46
 * @LastEditTime: 2023-03-26 00:16:02
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/sudoku.cpp
 * @Description: Please implement
 */

// 就是解数独

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
private:
    const int rows = 9;
    const int cols = 9;
public:
    bool valid(int row, int col, int num, vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i ++){
            if(board[row][i] - '0' == num || board[i][col] - '0' == num){
                return false;
            }
        }
        int block_x = row / 3;
        int block_y = col / 3;
        for(int i = block_x * 3 ; i < (block_x + 1) * 3 ; ++i){
            for(int j = block_y * 3 ; j < (block_y + 1) * 3 ; ++j){
                if(board[i][j] - '0' == num){
                    return false;
                }
            }
        }
        return true;
    }

    bool backtrack(int row, int col, vector<vector<char>>& board){
        for(int i = 1 ; i <= 9 ; i ++){
            if(valid(row, col, i, board)){
                bool temp = true;       // 非常重要, 否则的话，当在下面k的循环中，若没找到'.'， 则判断 if(!temp) 再Leetcode上会当作未初始化错误
                bool finish = true;
                board[row][col] = '0' + i;
                for(int j = row ; j < rows ; ++j){
                    for(int k = 0 ; k < cols ; ++k){
                        if(board[j][k] == '.'){
                            finish = false;
                            temp = backtrack(j, k, board);
                            if(temp) return true;
                            else break;
                        }
                    }
                    if(!temp) break;
                }
                if(finish) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // 只能使用回溯法
        /*
        对于每一个 '.' 元素, 进行 1 - 9 的填充, 然后寻找下一个'.'点.
        */
        bool solved = false;
        for(int i = 0 ; i < rows ; ++i){
            for(int j = 0 ; j < cols ; ++j){
                if(board[i][j] == '.'){
                    backtrack(i, j, board);
                    solved = true;
                    break;
                }
            }
            if (solved) break;
        }
    }
};

int main(){
    Solution s;
    vector<vector<char>> board {{'8','.','.','.','.','.','.','.','.'},
                                {'.','.','3','6','.','.','.','.','.'},
                                {'.','7','.','.','9','.','2','.','.'},
                                {'.','5','.','.','.','7','.','.','.'},
                                {'.','.','.','.','4','5','7','.','.'},
                                {'.','.','.','1','.','.','.','3','.'},
                                {'.','.','1','.','.','.','.','6','8'},
                                {'.','.','8','5','.','.','.','1','.'},
                                {'.','9','.','.','.','.','4','.','.'}};
    time_t start, end;
    start = clock();
    s.solveSudoku(board);
    end = clock();
    cout << "time:  " << ((end - start) / 1000) << "ms\n"; 
    for (const vector<char>& vec : board){
        for(const char& ch : vec){
            cout << ch << "  ";
        }
        cout << endl;
    }
    return 0;
}