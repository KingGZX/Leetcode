#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
    暂存复杂版解法，到时候会更新精简版解法
    */
    string solveEquation(string equation) {
        int x_coef = 0;     // x的系数
        int constant = 0;   // 移项后的常数项
        int coef = 0;
        int sig = 1;
        bool set_zero = false;
        bool reverse = false;   // 永远判定等号左端或右端
        for(const char ch : equation){
            if(ch == '='){   
                constant += coef * sig * (reverse == false ? 1 : -1);
                reverse = true;
                sig = 1;
                coef = 0;
                set_zero = false;
            }
            else if(ch == '+'){     // 遇到加号，可以让常数项加上系数coef，并且将coef清零
                constant += coef * sig * (reverse == false ? 1 : -1);
                sig = 1;
                coef = 0;
                set_zero = false;
            }
            else if(ch == '-'){     // 同理，不用担心coef是x的系数，因为一遇到x，在操作中会把coef清零！
                constant += coef * sig * (reverse == false ? 1 : -1);
                sig = -1;
                coef = 0;
                set_zero = false;
            }
            else if(ch >= '0' && ch <= '9'){
                coef = coef * 10 + int(ch - '0');
                if(ch == '0')
                    set_zero = true;
            }
            else if(ch == 'x'){
                if(coef == 0){
                    if(set_zero){
                        set_zero = false;
                        coef = 0;
                    }
                    else{
                        coef = 1;
                    }
                }
                x_coef += coef * sig * (reverse == false ? 1 : -1);
                coef = 0;
            }
        }
        if(coef != 0){
            constant += coef * sig * (reverse == false ? 1 : -1);
        }
        if(x_coef == 0 && constant == 0)
            return string("Infinite solutions");
        else if(x_coef == 0 && constant != 0)
            return string("No solution");
        else{
            int ans = -(constant / x_coef);
            return string("x=") + to_string(ans);;
        }
    }
};

int main(){
    Solution s;
    s.solveEquation("x-10=10-x+x+2x");
    return 0;
}