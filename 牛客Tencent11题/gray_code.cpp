/*
 * @author: Zhexuan Gu
 * @Date: 2022-12-28 10:40:40
 * @LastEditTime: 2022-12-28 12:22:41
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/gray_code.cpp
 * @Description: Problem1
 */
#include <iostream>
#include <vector>
using namespace std;

/*
描述
在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，
请编写一个函数，使用递归的方法生成N位的格雷码。

给定一个整数n，请返回n位的格雷码，顺序为从0开始。

测试样例：
1
返回：["0","1"]
*/

/*
"""
----------------------------Solution ----------------------
主要是观察到格雷编码的对称性，比如先列举一个n = 3时的有效解
000
001
011
010
110
111
101
100

不难看出前四个与后四个，除了首位字符，后面都是对称的！

所以初始状态下(n = 1时)我们的解为:
0 1

由于要从0开始，所以为了构造n = 2的解，我们在第一个字符0后面 分别加上0 和 1得到
00 01
而由上对称性可知，字符1后面则需要分别加上 1 和 0
11 10
所以得到n = 2的解为：
00 
01
11
10

最后推导n = 3时的情况，先对 00 操作得到 000 001. 
然后注意，对 01 就要先加 1 否则无法满足相邻只差一位编码的要求，得到 011 010. 
对 11 又要转回先加 0 得到 110 111.
所以要注意的就是 append 0 or 1 时有一个逆序的操作。
"""
*/

class GrayCode {
private:
    vector<string> ans;
    vector<string> temp{"0", "1"};
    vector<char> postfix{'0', '1'};
public:
    void backtrack(int cnt, int n) {
        if(cnt == n)
            return;
        vector<string> ttemp;
        int negation = 1;
        for(string str : temp){
            for(char ch : postfix){
                if(negation < 0){
                    if(ch == '0')
                        ch = '1';
                    else
                        ch = '0';
                }
                ttemp.emplace_back(str + ch);    
            }
            negation = -negation;
        }
        temp = ttemp;
        backtrack(cnt + 1, n);
    }
    vector<string> getGray(int n) {
        // write code here
        backtrack(1, n);
        ans = temp;
        return ans;
    }
};

int main(){
    GrayCode test;
    vector<string> ans = test.getGray(3);
    for(const string elem : ans){
        cout << elem << endl;
    }
    return 0;
}


/*
我自己实际上对对称没理解到位，看了别人的java版本，才觉得那样更好，附上：
public String[] GrayCode(int n) {
 
	// produce 2^n grade codes
    String[] graycode = new String[(int) Math.pow(2, n)];
 
    if (n == 1) {
    	graycode[0] = "0";
    	graycode[1] = "1";
        return graycode;
    }
 
    String[] last = GrayCode(n - 1);
 
    for (int i = 0; i < last.length; i++) {
    	graycode[i] = "0" + last[i];
    	graycode[graycode.length - 1 - i] = "1" + last[i];
    }
 
    return graycode;
}
*/