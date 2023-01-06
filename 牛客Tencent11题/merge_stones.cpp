/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-06 20:51:13
 * @LastEditTime: 2023-01-06 20:58:37
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/merge_stones.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
描述
小Q和牛博士在玩一个石子合并的游戏，初始一共有n堆石子，每堆石子有w[i]个石子。
小Q和牛博士他们需要对石子堆进行合并，每次他们可以任意选择两堆石子进行合并。
一堆有x个石子的石子堆和一堆有y个石子的石子堆合并将得到一堆x+y个石子的石子堆，这次合并得分为x*y，当只剩下一堆石子的时候游戏结束。

小Q和牛博士希望采取优秀的策略获得最大得分，希望你能来帮他们算算最大得分多少。

输入描述： 输入包括两行，第一行一个正整数n(2≤n≤100)。 第二行包括n个正整数w[i](1≤w[i]≤100)，即每堆石子的个数。
输出描述： 输出一个正整数，即小Q和牛博士最大得分是多少。
示例1
输入：
3
1 2 3

输出：
11
*/

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int ans = vec[0] * vec[1];
    int prev = vec[0] + vec[1];
    for(int i = 2 ; i < n ; i ++){
        ans += prev * vec[i];
        prev += vec[i];
    }
    cout << ans << endl;
    return 0;
}

/*
一种类似贪心的思想:
    我们让最重的石子堆不要先去被合并掉,让他最后被合并
    最轻的石子堆不要去和高质量石子堆合并(比如 1、4、10,  1，10合起来没必要，让1和4先合) 
*/