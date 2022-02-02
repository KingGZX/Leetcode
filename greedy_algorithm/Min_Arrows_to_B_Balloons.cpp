/*
Q452
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 
且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。
我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。


输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
首先要理解题目的含义：
    我们的射箭方向是垂直于x轴的，这只箭只要擦到了球的边界就视为扎爆

    比如以[[1, 2], [2, 3], [3, 4], [4, 5]]案例为范例：
        第一支箭x = 2扎爆前两个，第二支箭x = 4扎爆后两个，所以共需两支箭

    使用贪心的思想解决本题[小tip，很多运用贪心算法思想的题目都需要排序，至少对一个变量是有序的，但只是大部分情况]：
    这里我们对points数组按照每个气球的右端点排序，从小到大。
        比如第一个案例，拍完后的points数组应为：[[1, 6], [2, 8], [7, 12], [10, 16]],
        此时由于我们的右端点是有序的，以第一第二个气球为例，只要我们确保第二个气球的左端点小于第一个气球的右端点
        就确定可以仅用一只箭同时扎爆。[比如令箭的x = 第一个气球的右端点，必扎爆俩]

        反之如果遍历到的当前气球的左端点超出了我们维护的右端点
        维护的右端点：[因为不一定是前一个气球的右端点，比如一支箭扎爆10个，维护的仍旧是10个之前的]
        我们就需要增加一支箭，同时将维护的右端点改为当前这个气球的右端点
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty() || points.size() == 1) return points.size(); 
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2){
            return p1[1] < p2[1];
        });    // sort the points vector by each ballon's end_point
        int num = 1;
        int end_point_end = points[0][1];
        for(int i = 1 ; i < points.size() ; i ++){
            if(points[i][0] > end_point_end){
                num ++;
                end_point_end = points[i][1];
            }
        }
        return num;
    }
};

int main(){
    vector<vector<int>> vec{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    Solution s;
    cout << s.findMinArrowShots(vec) << endl;
    return 0;
}