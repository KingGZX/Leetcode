/*
 * @author: Zhexuan Gu
 * @Date: 2022-09-21 17:36:52
 * @LastEditTime: 2022-09-21 18:16:22
 * @FilePath: /CPPprojects/Leetcode/DataStructure_PolyU/Queue_and_Stack/test.cpp
 * @Description: Please implement
 */


#include <iostream>
#include "stack.h"

using namespace std;
using namespace gzx_simple_stl;

int main(){
    MyStack<int> obj(5);
    int a = 3, b = 4, c = 5;
    int t;
    obj.Push(a);
    obj.Push(c);
    obj.Pop(t);
    cout << t << endl;
    obj.Push(b);
    obj.Pop(t);
    cout << t << endl;
    return 0;
}