/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-02 12:37:34
 * @LastEditTime: 2023-01-02 12:57:56
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/prime_pairs.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
描述
给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
输入描述： 输入包括一个整数n,(3 ≤ n < 1000)
输出描述： 输出对数
示例1
输入： 10
输出： 2
*/

int main(){
    // 普通的素数判别法就是 for 循环 从2 到 sqrt(n), 只要都不能整除便是素数

    // 用欧拉筛法可以加速判断
    vector<int> primes(1000, 1);        // 初始化每个都是素数
    for(int i = 2 ; i < 1000 ; i ++){
        // 对于素数的j倍 剔除
        for(int j = 2 ; j * i < 1000 ; j ++){
            if(primes[i]){
                primes[i * j] = 0;
            }
        }
    }

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 2 ; i <= (n >> 1) ; i ++){
        if(primes[i] && primes[n - i]){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}