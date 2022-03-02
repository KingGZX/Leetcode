/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"

示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I

示例 3：
输入：s = "A", numRows = 1
输出："A"
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    // 下面的代码是硬模拟，down确定目前在 "往上" 还是 "往下"安插字母
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() == 1 || s.length() == 0 || s.length() <= numRows) return s;
        vector<char> vec[numRows];
        bool down = true;
        int ptr = 0;
        for(int i = 0 ; i < s.length() ; i ++){
            if(down){
                vec[ptr++].push_back(s[i]);
                if(ptr == numRows){
                    down = false;
                    ptr = numRows - 2;
                }
            }
            else{
                vec[ptr--].push_back(s[i]);
                if(ptr == -1){
                    ptr = 1;
                    down = true;
                }
            }
        }
        string ans = "";
        for(int i = 0 ; i < numRows ; i ++){
            for(char ch : vec[i]){
                ans += ch;
            }
        }
        return ans;
    }
    */
    // 直接用数学找规律的方法安插
    /*
    以示例2为参考对象：
        一个轮回，应该是6个字符 设为step

        第一行(index = 0)的字符序号分别是 0->6->12
            间距都是6，即都是step

        第二行(index = 1)的字符序号分别是 1->5->7->11->13
            间距分别是 4 2 4 2   即都是 step - 2 * index 和 2 * index

        第三行(index = 2)的字符序号分别是 2->4->8->10 
            间距分别是 2 4 2     即都是 step - 2 * index 和 2 * index
        
        第四行(index = 3)的字符序号分别是 3->9
            间距都会是6    即为step
    
    其实对于整个zigzag排序都有这样的规律，即首尾两行步长固定 = 周期，中间的都是 step - 2 * row 和 2 * row之间来回切换
    */
    string convert(string s, int numRows){
        if(numRows >= s.length()) return s; // 就只能排一列
        string ans = "";
        int step = numRows * 2 - 2; // 周期，也即我们需要的步长
        for(int i = 0 ; i < numRows ; i ++){    // 对行遍历，因为我们已经找到了某一行的特定排序规律
            int index = i;
            int add = 2 * i;
            while(index < s.length()){
                ans += s[index];
                add = step - add;   // 对于非首尾行的元素，步长一直在 step - 2 * row 和 2 * row之间变化
                index += (i == 0 || i == numRows - 1) ? step : add;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]){
    Solution s;
    s.convert("PAYPALISHIRING", 4);
    return 0;
}
