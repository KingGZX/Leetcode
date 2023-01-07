/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-07 12:46:28
 * @LastEditTime: 2023-01-07 14:49:25
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/magic_matrix.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
描述
小Q搜寻了整个魔法世界找到了四块魔法石所在地，当4块魔法石正好能构成一个正方形的时候将启动魔法阵，小Q就可以借此实现一个愿望。

现在给出四块魔法石所在的坐标，小Q想知道他是否能启动魔法阵

输入描述：
输入的第一行包括一个整数（1≤T≤5）表示一共有T组数据

每组数据的第一行包括四个整数x[i](0≤x[i]≤10000)，即每块魔法石所在的横坐标

每组数据的第二行包括四个整数y[i](0≤y[i]≤10000),即每块魔法石所在的纵坐标
输出描述： 对于每组数据，如果能启动魔法阵输出“Yes”否则输出“No”。
示例1
输入：
3
0022
0202
0156
1605
0077
0303

输出：
Yes
Yes
No
*/
// --------------比较简单,本质上就是那个经典的能否构成正方形问题... 我们只需知道正方形的两条对角线作向量处理时长度相等且垂直--------------//

struct Vertex{
    int p1;
    int p2;
    int p3;
    int p4;
};

bool orthogonalequivalent(int vec1x, int vec1y, int vec2x, int vec2y){
    if(vec1x * vec2x + vec1y * vec2y == 0){
        if(pow(vec1x, 2) + pow(vec1y, 2) == pow(vec2x, 2) + pow(vec2y, 2)){
            return true;
        }
        return false;
    }
    return false;
}

bool ComposeSquare(Vertex x, Vertex y){
    if(orthogonalequivalent(x.p1 - x.p2, y.p1 - y.p2, x.p3 - x.p4, y.p3 - y.p4) || 
        orthogonalequivalent(x.p1 - x.p4, y.p1 - y.p4, x.p3 - x.p2, y.p3 - y.p2) ||
        orthogonalequivalent(x.p1 - x.p3, y.p1 - y.p3, x.p2 - x.p4, y.p2 - y.p4)){
            return true;
        }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<Vertex> Xlabel(n);
    vector<Vertex> Ylabel(n);
    string s1, s2;
    for(int i = 0 ; i < n ; i ++){
        /*
        非常怪异的数据输入方式。。。。
        题目的输入是字符串形式的。。。。。 所以虽然题目说 “0≤x[i]≤10000” 如果你被给到一组数 比如 12344657 , 你根本不知道怎么拆分四个数。。

        所以,实际上测试数据都是个位数 即 0-9的, 所以用字符串的每一位作为一个输入即可...
        */
        cin >> s1 >> s2;
        Xlabel[i].p1 = s1[0] - '0', Xlabel[i].p2 = s1[1] - '0', Xlabel[i].p3 = s1[2] - '0', Xlabel[i].p4 = s1[3] - '0';
        Ylabel[i].p1 = s2[0] - '0', Ylabel[i].p2 = s2[1] - '0', Ylabel[i].p3 = s2[2] - '0', Ylabel[i].p4 = s2[3] - '0';
    }
    for(int i = 0 ; i < n ; i ++){
        if(ComposeSquare(Xlabel[i], Ylabel[i])){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}