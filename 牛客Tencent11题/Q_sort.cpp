/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-09 11:16:03
 * @LastEditTime: 2023-01-09 11:27:31
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/Q_sort.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;

/*
描述
小Q在学习许多排序算法之后灵机一动决定自己发明一种排序算法，小Q希望能将n个不同的数排序为升序。小Q发明的排序算法在每轮允许两种操作：

1、 将当前序列中前n-1个数排为升序

2、 将当前序列中后n-1个数排为升序

小Q可以任意次使用上述两种操作，小Q现在想考考你最少需要几次上述操作可以让序列变为升序。

输入描述： 输入包括两行，第一行包括一个正整数n(3≤n≤10^5)，表示数字的个数

第二行包括n个正整数a[i](1≤a[i]≤10^9)，即需要排序的数字，保证数字各不相同。
输出描述： 输出一个正整数，表示最少需要的操作次数

示例1
输入：
6
4 3 1 6 2 5

输出：
2
*/

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> vec[i];
    }
    bool needSort = false;
    int mmin = vec[0], mmax = vec[0];
    for(int i = 1 ; i < n ; i ++){
        if(vec[i] < vec[i - 1]){
            mmin = min(mmin, vec[i - 1]);
            needSort = true;
        }
        else{
            mmax = max(mmax, vec[i]);
        }
    }
    if(!needSort){
        cout << "0\n";
    }
    else{
        if(mmin == vec[0] || mmax == vec[n - 1]){
            cout << "1\n";
        }
        else if(mmin == vec[n - 1] && mmax == vec[0]){
            cout << "3\n";
        }
        else{
            cout << "2\n";
        }
    }
    return 0;
}

/*
个人思路很简单:
    就只要关注数组中最大和最小俩数的位置就够了

    如果最大在第一位且最小在最后一位 那么需要经历 3 次 才行
    如果两者仅有一者满足情况        那么仅需 2 次
    如果最小的在最前 或者 最大的在最后 那么仅需 1 次
    否则都需要两次  (------这种情况 与 上述第二种情况 可以合并 ) 具体见代码即可

    当然，有一个大前提就是我们需要事先看看数组是不是本身就是有序的
*/