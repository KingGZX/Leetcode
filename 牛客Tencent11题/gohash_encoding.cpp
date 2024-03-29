/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-04 09:40:44
 * @LastEditTime: 2023-01-04 10:23:14
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/gohash_encoding.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
描述
geohash编码：geohash常用于将二维的经纬度转换为字符串，分为两步：第一步是经纬度的二进制编码，第二步是base32转码。
此题考察纬度的二进制编码：算法对纬度[-90, 90]通过二分法进行无限逼近（取决于所需精度，本题精度为6）。
注意，本题进行二分法逼近过程中只保留整数部分而忽略掉小数部分（也即抹去小数部分）来进行二分，针对二分中间值属于右区间。
算法举例如下： 针对纬度为80进行二进制编码过程：
1) 区间[-90, 90]进行二分为[-90, 0),[0, 90]，成为左右区间，可以确定80为右区间，标记为1；
2) 针对上一步的右区间[0, 90]进行二分为[0, 45),[45, 90]，可以确定80是右区间，标记为1；
3) 针对[45, 90]进行二分为[45, 67),[67,90],可以确定80为右区间，标记为1；
4) 针对[67,90]进行二分为[67, 78),[78,90]，可以确定80为右区间，标记为1；
5) 针对[78, 90]进行二分为[78, 84),[84, 90]，可以确定80为左区间，标记为0；
6) 针对[78, 84)进行二分为[78, 81), [81, 84)，可以确定80为左区间，标记为0；
输入描述： 输入包括一个整数n,(-90 ≤ n ≤ 90)
输出描述： 输出二进制编码
示例1
输入： 80
输出： 111100
示例2
输入： -66
输出： 001000
说明：
1) 区间[-90, 90]进行二分为[-90, 0),[0, 90]，成为左右区间，可以确定-66在左区间，标记为0；
2) 针对上一步的左区间[-90, 0)进行二分为[-90, -45),[-45, 0)，可以确定-66在左区间，标记为0；
3) 因(-90-45)/2=-135/2=-67.5，只取整数部分可得-67，所以针对[-90, -45)进行二分为[-90, -67),[-67,-45),可以确定-66在右区间，标记为1；
4) 针对[-67,-45)进行二分为[-67, -56),[-56,-45]，可以确定-66在左区间，标记为0；
5) 因(-67-56)/2=-123/2=-61.5，只取整数部分可得-61，所以针对[-67, -56)进行二分为[-67, -61),[-61, -56]，可以确定-66在左区间，标记为0；
6) 针对[-67, -61)进行二分为[-67, -64), [-64, -61)，可以确定-66在左区间，标记为0； 
*/

const size_t precision = 6;

void dichotomy(int left, int right, string& encoder, const int target){
    if(encoder.length() >= precision)
        return;
    int mid = floor((left + right) / 2);
    if(target >= mid){
        encoder += '1';
        dichotomy(mid, right, encoder, target);
    }
    else{
        encoder += '0';
        dichotomy(left, mid, encoder, target);
    }
}

int main(){
    string ans = "";
    int n;
    cin >> n;
    dichotomy(-90, 91, ans, n);
    cout << ans << endl;
    return 0;
}