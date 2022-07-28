#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。

点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。

一个 有效的正方形 有四条等边和四个等角(90度角)。

 

示例 1:

输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True
示例 2:

输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
输出：false
示例 3:

输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
输出：true

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int callen(int x1, int y1, int x2, int y2){
        // 返回向量模长平方
        return pow(x2 - x1, 2) + pow(y2 - y1, 2);
    }
    bool perpendicular(int vec1x, int vec1y, int vec2x, int vec2y){
        // 向量内积为零代表垂直
        if(vec1x * vec2x + vec1y * vec2y == 0)
            return true;
        return false;
    }
    bool diagnal(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y){
        // 1.假如p1p2构成的是一条对角线
        int midp1p2x = (p1x + p2x) >> 1;
        int midp1p2y = (p1y + p2y) >> 1;
        int midp3p4x = (p3x + p4x) >> 1;
        int midp3p4y = (p3y + p4y) >> 1;
        // 对角线向量相互垂直且相交点均为两者中点，且两者模长相同则为正方形
        if(perpendicular(p2x - p1x, p2y - p1y, p4x - p3x, p4y - p3y)){
            if(midp1p2x == midp3p4x && midp1p2y == midp3p4y){
                int len = callen(p1x, p1y, p2x, p2y);
                if(len && len == callen(p3x, p3y, p4x, p4y))
                    return true;
            }
        }
        return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
        p1x = p1[0];
        p1y = p1[1];
        p2x = p2[0];
        p2y = p2[1];
        p3x = p3[0];
        p3y = p3[1];
        p4x = p4[0];
        p4y = p4[1];
        // 假设p1p2 构成对角线. 假设p1p3构成对角线. 假设p1p4构成对角线.
        if(diagnal(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y) ||
        diagnal(p1x, p1y, p3x, p3y, p2x, p2y, p4x, p4y) ||
        diagnal(p1x, p1y, p4x, p4y, p2x, p2y, p3x, p3y)){
            return true;
        }
        return false;
    }
};