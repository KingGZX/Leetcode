/*
Q435
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

例：
    输入: [ [1,2], [2,3], [3,4], [1,3] ]

    输出: 1

    解释: 移除 [1,3] 后，剩下的区间没有重叠。

    输入: [ [1,2], [1,2], [1,2] ]

    输出: 2

    解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
贪心思路：
    对于一个区间，我们总是是取右端点最小的亦或是左端点最大的，这样最不容易产生重叠！
    所以此题本意并不是去删除一些区间再去模拟是否重合，应该是不断去选取不会重合的最多数量的区间，最后相减得到解
    上面的思路基于我们对区间块根据右端点进行从小到大排序。

    当然我们还可以根据左端点从小到大排序，此时我们就要做逆序的遍历。
    因为左端点越大，其前面的空间就相应越大！
    我们固定好左端点后就向前遍历去取右端点小于刚刚那个左端点的值，更新新的左端点。
    
    以下代码遵从第一种思路。
*/

class Solution {
public:
    static bool cmp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[1] < vec2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int num = 1;
        int right_border = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; i ++){
            if(intervals[i][0] >= right_border){
                right_border = intervals[i][1];
                num ++;
            }
        }
        int ans = intervals.size() - num;
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec{{1, 2}, {2, 3}, {1, 3}, {3, 4}};
    s.eraseOverlapIntervals(vec);
    return 0;
}