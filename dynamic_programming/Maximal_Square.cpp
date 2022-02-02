/*
Q221
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

 

示例 1：


输入：matrix = [["1","0","1","0","0"],
                ["1","0","1","1","1"],
                ["1","1","1","1","1"],
                ["1","0","0","1","0"]]
输出：4
示例 2：


输入：matrix = [["0","1"],
                ["1","0"]]
输出：1
示例 3：

输入：matrix = [["0"]]
输出：0

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int mmax_side = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i = 0 ; i < row ; i ++){
            for(int j = 0 ; j < col ; j ++){
                if(matrix[i][j]){
                    if(i == 0 || j == 0){    
                        mmax_side = max(mmax_side, 1);   
                        dp[i][j] = matrix[i][j];   
                        // 第0行或者第0列，都结合不成正方形，只有可能自己本身一小块作为正方形
                    }
                    else{
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                        mmax_side = max(mmax_side, dp[i][j]);
                    }
                }
            }
        }
        return mmax_side * mmax_side;
    }


    // 一个小技巧就是把dp数组扩一行一列 这样i == 0 和 j == 0的情况可以一同处理
    int maximalSquare2(vector<vector<char>>& matrix) {
        int side = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for(int i = 1 ; i <= row ; i ++){
            for(int j = 1 ; j <= col ; j ++){
                if(matrix[i - 1][j - 1] == '1'){    
                    // 因为matrix是无法访问到row 和 col的，所以做减一处理，相当于把增加的一行一列回退，映射回去
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    side = max(side, dp[i][j]);
                }
            }
        }
        return side * side;
    }
};

int main(){
    return 0;
}