/*
Q658

给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
示例 2：

输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]
*/

#include <iostream>
#include <unistd.h>
#include <vector>
#include <queue>
using namespace std;

//  最开始的思路很暴力，先按照和x的距离从小到大进行排序
//  然后取出前k个最近距离的点，将这k个点按照在数组中的下标从小到大排序
//  最后就是将这k个下标取出相应值放入最后的答案
class Solution1 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> vec;
        for(int i = 0 ; i < arr.size() ; i ++){
            vec.push_back(pair<int, int>(i, abs(arr[i] - x)));
        }
        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b){
                if(a.second == b.second)
                    return a.first < b.first;
                return a.second < b.second;   
        });
        vector<pair<int, int>> ans(vec.begin(), vec.begin() + k);
        vector<int> ret;
        sort(ans.begin(), ans.end(), [](pair<int, int>& a, pair<int, int>& b){
                return a.first < b.first;
        });
        for(int i = 0 ; i < k ; i ++){
            ret.push_back(arr[ans[i].first]);
        }
        return ret;
    }
};

int main(){
    
}