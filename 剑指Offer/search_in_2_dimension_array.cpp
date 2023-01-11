/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-10 18:43:32
 * @LastEditTime: 2023-01-10 19:16:19
 * @FilePath: /CPPprojects/Leetcode/剑指Offer/search_in_2_dimension_array.cpp
 * @Description: Please implement
 */
/*
剑指 Offer 04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool binarysearch(vector<int> vec, int target, int left, int right){
        if(left >= right) return false;
        int mid = (left + right) >> 1;
        if(target == vec[mid]) return true;
        if(target > vec[mid]) return binarysearch(vec, target, mid + 1, right);
        else return binarysearch(vec, target, 0, mid);
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row) return false;
        int col = matrix[0].size();
        if(!col) return false;
        bool ans = false;
        for(int i = 0 ; i < row ; i ++){
            if(target > matrix[i][col - 1]) continue;
            else if(target >= matrix[i][0] && target <= matrix[i][col - 1]){
                if(binarysearch(matrix[i], target, 0, col)){
                    ans = true;
                    break;
                }
            }
            else if(target < matrix[i][0]) break;
        }
        return ans;
    }
};



int main(){
    vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
    Solution s;
    s.findNumberIn2DArray(matrix, 5);
    return 0;
}