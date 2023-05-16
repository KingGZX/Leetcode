/*
 * @author: Zhexuan Gu
 * @Date: 2023-05-14 10:45:51
 * @LastEditTime: 2023-05-14 10:51:10
 * @FilePath: /CPPprojects/Leetcode/CPP_Traits/function_ptr.cpp
 * @Description: Please implement
 */
#include <iostream>
using namespace std;

int mmm(void){
    return 23;
}

string& hello(int m, int n){
    int c = m + n;
    string* temp = new string("Hello, World!");
    return *temp;
}

int main(){
    int (*func)(void);
    func = mmm;
    cout << func() << endl;

    string& (*ff)(int, int);
    ff = hello;
    cout << ff(1, 2) << endl;
    return 0;
}