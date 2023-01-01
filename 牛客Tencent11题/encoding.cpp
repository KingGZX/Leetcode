/*
 * @author: Zhexuan Gu
 * @Date: 2022-12-31 13:14:27
 * @LastEditTime: 2022-12-31 18:04:19
 * @FilePath: /CPPprojects/Leetcode/牛客Tencent11题/encoding.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
描述
假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： 
a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 
其中 a 的 Index 为 0 ，aa 的 Index 为 1，aaa 的 Index 为 2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
输入描述： 输入一个待编码的字符串,字符串长度小于等于100.
输出描述： 输出这个编码的index
示例1
输入： baca
输出： 16331
*/

class Encode{
private:
    int fix1, fix2, fix3;
    int num;
public:
    Encode(int f1 = 25, int f2 = 25 * 25, int f3 = 25 * 25 * 25):fix1(f1), fix2(f2), fix3(f3), num(f1 + f2 + f3 + 1){};
    int getIndex(string str){
        int index = 0;
        for(size_t i = 0 ; i < str.length() ; i ++){
            if(i == 0 && str[i] > 'a'){
                /*
                对于第一个字符,假如是'a'就不做处理,否则就得把之前的num全给加上
                num代表了以某个字符打头的所有可能
                */
                index += num * int(str[i] - 'a');
            }
            else if(i == 1){
                if(str[i] == 'a') index ++;
                else{
                    // e.g. "acxx"
                    // 那么就是把 aaxx aax aa 和 abxx abx ab 全加进来
                    index += int(str[i] - 'a') * (fix2 + fix1 + 1);
                    index ++;
                }
            }
            else if(i == 2){
                if(str[i] == 'a') index ++;
                else{
                    // e.g. "acex"
                    // 那么就是把 acax acbx accx acdx aca acb acc acd 全加进来
                    index += int(str[i] - 'a') * (fix1 + 1);
                    index ++;
                }
            }
            else{
                if(str[i] == 'a') index ++;
                else{
                    index += int(str[i] - 'a');
                    index ++;
                }
            }
        }
        return index;
    }
};

int main(){
    string s;
    cin >> s;
    Encode demo;
    int index = demo.getIndex(s);
    cout << index << endl;
    return 0;
}