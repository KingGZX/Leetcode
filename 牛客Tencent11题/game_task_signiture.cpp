/*
 * @author: Zhexuan Gu
 * @Date: 2023-01-01 14:02:42
 * @LastEditTime: 2023-01-01 18:17:48
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/game_task_signiture.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
using namespace std;


/*
描述
游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。
请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 
输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 
输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
输入描述： 输入包括一行,两个整数表示任务ID.
输出描述： 输出是否完成
示例1
输入： 1024 1024
输出： 1
*/


// 本low bee 的初始code   -----(没错,题意就是你们想的那样的,判断两个数是否在[1,1024],随后再判断两者是否相同即可)-----
/*
int main() {
    int a, b;
    cin >> a >> b;
    if(a < 1 || a > 1024 || b < 1 || b > 1024){
        cout << -1 << endl;
    }
    else if(a == b){
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
*/


int main(){
    // 正确操作是应用 "位运算" 的技巧

    /*
    用32个整数表示1024位,因为一个整数是32位
    所以把32个整数排成一串,某一bit为1就可以代表相应index的任务已完成

    用输入的index 
    index % 32 ---- (把某一个整数32bit的此位置改为1) 和 index / 32 ----- (数组中的位置) 来标记此任务的bit位

    这里有一点需要注意,就是index % 32只是确保了每一个task有其专属位置,并不是说

    1024:   000000.......000001
    1023:   000000.......000010

    这样按顺序的
    */
    int a, b;
    cin >> a >> b;
    unsigned int arr[32];
    if(a < 1 || a > 1024 || b < 1 || b > 1024){
        cout << -1 << endl;
    }
    else{
        arr[(a - 1) >> 5] |= (1 << (a & 31));
        cout << ((arr[(b - 1) >> 5] & (1 << (b & 31))) != 0) << endl;
    }
    return 0;
}