/*
Q69
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

 

示例 1：

输入：x = 4
输出：2
示例 2：

输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
*/

#include <iostream>
#include <math.h>
using namespace std;

/*
用到的是二分法的思想：
    可以 一开始想象成从  0 - x的二分
    然后从  x / 2 ~  x  |   0 ~  x / 2的二分，持续
*/
class Solution {
public:
    // 其实下列代码，只需要把循环条件设置成 left <= right 就无须另外在循环外面进行额外计算了
    int mySqrt(int x) {
        if(!x) return x;
        int left = 1;
        int right = x;
        while(left < right){
            int mid = left + ((right - left) >> 1);    // avoid left + right  ----> out of range
            // 因为遇到大整数时  mid * mid会溢出，但换成除法就不会受影响
            int res = x / mid;
            if(res == mid) return mid;
            else if(res < mid) right = mid - 1;     // mid is too big
            else left = mid + 1;
        }
        if(x / left < left)     // consider the example '8':  at last, left = right = 3, but we should return 2
            return left - 1;
        return left;
    }

    // 从更加数学层面考虑，用牛顿迭代法是一个非常好的方法
    int Newton(int x){
        if(!x) return x;
        /*
        把求解想成 --->    解二次函数  x² - a = 0   ， 且我们只找正根
        我们一开始设置一个初始假想根 x0
        然后根据导数知识 --- >    从 (x0, f(x0))引一条切线，与x轴的交点设为下一轮迭代值
        切线导数为2x0
        f(x0) = 2x0(x0 - x1)    ----->    x1 = x0 - f(x0) / 2x0    -----> x1 = x0 / 2 + a / 2x0
        一般而言初始值我们假想为x
        */
        double a = x, x0 = x;
        while(true){
            double x1 = x0 / 2 + a / (2 * x0);
            if(fabs(x1 - x0) < 1e-7){      // 我们认为迭代值小于这个误差时就已经趋于完美
                break;
            }
            x0 = x1;
        }
        return (int)x0;
    }
};

int main(){
    Solution s;
    s.mySqrt(8);
    return 0;
}