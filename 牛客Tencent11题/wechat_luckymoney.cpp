/*
 * @author: Zhexuan Gu
 * @Date: 2022-12-30 11:04:10
 * @LastEditTime: 2022-12-30 11:20:15
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/wechat_luckymoney.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
描述
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。

给定一个红包的金额数组 gifts 及它的大小 n ，请返回所求红包的金额。

若没有金额超过总数的一半，返回 0。

数据范围：1 ≤ n ≤ 1000  ,红包金额满足 1 ≤ gift_i ≤ 100000
示例1
输入：  [1,2,3,2,2],5
返回值： 2


示例2
输入：  [1,1,2,2,3,3],6
返回值： 0
*/


/*

思路和大多数人提供的一致, Hash的思想

*/

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        map<int, int> HashMap;
        for(const int gift : gifts){
            HashMap[gift] += 1;
            if(HashMap[gift] > (n >> 1))
                return gift;
        }
        return 0;
    }
};

int main(){

    return 0;
}