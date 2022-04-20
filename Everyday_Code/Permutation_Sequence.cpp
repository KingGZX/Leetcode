/*
Q60
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

示例 1：

输入：n = 3, k = 3
输出："213"
示例 2：

输入：n = 4, k = 9
输出："2314"
示例 3：

输入：n = 3, k = 1
输出："123"
*/


#include <iostream>
#include <vector>
using namespace std;

/*
思路：
    不断地去确定某一位数字
    比如确定第一位时，以每一个数字开头的都是 (n - 1)!种情况
        以题目给出的2为例：
            第一位数字固定下来的话，后续只有3！种排序，那么以1开头总共只有6种，不够k = 9
            所以当第一位数字取2时，6 + 6 = 12 > 9，就可以确定第一位数字是2了。

            其余的可以看代码理解
*/

class Solution {
public:
    int fact(int n){
        int ans = 1;
        for(int i = 1 ; i < n ; i ++){
            ans *= i;
        }
        return ans;
    }

    string getPermutation(int n, int k) {
        string ans = "";
        int temp = n;
        int nums = 0;
        vector<bool> visited(n + 1, false);
        while(ans.length() != n){
            int fac = fact(temp);
            int ch = 0;
            int cnt = 1;
            for(int i = 1 ; i <= n ; i ++){
                if(visited[i]) continue;
                if(nums + cnt * fac >= k){
                    nums += (cnt - 1) * fac;
                    ch = i;
                    visited[i] = true;
                    break;
                }
                cnt ++;
            }
            ans += ch + '0';
            temp--;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
