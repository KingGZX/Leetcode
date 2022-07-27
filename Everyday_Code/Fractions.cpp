#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

class Fraction{
    private:
        int dominator;
        int numerator;
        int sign;
        static int gcd(int a, int b){   // 用欧几里得法求解两数的最大公因数 greatest common dividend
            a = abs(a);
            b = abs(b);
            if(!b) return a;
            if(a < b)   swap(a, b);
            /*
            以45 27为例:
            1. 45 % 27 = 1 ······ 18
            2. 27 % 18 = 1 ······ 9
            3. 18 % 9 = 2 ······ 0 (除尽，取9为 最大公因数)
            */
           while(a % b){
                int temp = a % b;
                a = b;
                b = temp;
           }
           int ans = b;
           return ans;
        };
    public:
        int getDom() const {return dominator;}
        int getNum() const {return numerator;}
        int getSign() const {return sign;}

        // 用一个整数构造
        Fraction(int num){
            // 即整数化为 num / 1
            this->sign = 1;
            if(num < 0){
                this->sign = -1;
                num = -num;
            }
            this->numerator = num;
            this->dominator = 1;
        }

        // 用分子分母进行构造
        Fraction(int a, int b){
            // 现判定符号
            this->sign = 1;
            if(a * b < 0)   this->sign = -1;
            if(a < 0) a = -a;
            if(b < 0) b = -b;
            this->numerator = a;
            this->dominator = b;
        }

        // 由字符串创建(注意应该是输入字符串的子串，其中只包含了一个分数对象)
        Fraction(const string& serialized, int begin, int end){
            // 先判断字符串本身是否存在问题
            if(end - begin <= 0){
                this->numerator = 0;
                this->dominator = 1;
                this->sign = 1;
                return;
            }
            // 看看输入头是否带有符号
            if(serialized[begin] == '-'){
                this->sign = -1;
                ++begin;
            }
            else if(serialized[begin] == '+'){
                this->sign = 1;
                ++begin;
            }
            // 确认完符号，可以先找分子
            int num = 0;
            while(begin < end && serialized[begin] != '/'){
                num = num * 10 + int(serialized[begin++] - '0');
            }
            this->numerator = num;

            num = 0;
            ++begin; // 越过'/'
            // 可能没有分母？？
            if(begin >= end) this->dominator = 1;

            // 开始提取分母
            while(begin < end){
                num = num * 10 + int(serialized[begin++] - '0');
            }
            this->dominator = num;
        }

        //重载分数加法
        Fraction& operator+(const Fraction& obj){
            int _gcd = gcd(this->dominator, obj.getDom());
            //通分
            int facthis = this->dominator / _gcd;
            int facobj = obj.getDom() / _gcd;
            int newDom = facobj * facthis * _gcd;
            int newNum = this->sign * this->numerator * facobj + obj.getSign() * obj.getNum() * facthis;
            this->dominator = newDom;
            this->sign = 1;
            if(newNum < 0){
                this->sign = -1;
                newNum = -newNum;
            }
            this->numerator = newNum;
            return *this;
        }

        //为分子分母约分
        Fraction& standarize(){
            int _gcd = gcd(this->dominator, this->numerator);
            this->numerator /= _gcd;
            this->dominator /= _gcd;
            return *this;
        }

        void setSign(int _sign){
            this->sign = _sign;
        }

        //结果的输出，字符串形式输出
        string serialize(){
            return to_string(this->sign * this->numerator) + "/" + to_string(this->dominator);
        }

        // 打印输出  ----可以用于debug时使用ß
        void show(){
            if(sign == -1) cout << "-";
            cout << this->numerator;
            cout << "/";
            cout << this->dominator;
            cout << endl;
        }
};

class Solution {
public:
    string fractionAddition(string expression) {
        Fraction f(0);
        int ptr = 0;
        int len = expression.length();
        int sign = 1;
        while(ptr < len){
            int end = ptr;
            while(end < len && expression[end] != '+' && expression[end] != '-'){
                ++end;
            }
            Fraction temp(expression, ptr, end);
            temp.setSign(sign);
            f = f + temp;
            f.standarize();
            if (end < len) {
                if (expression[end] == '+') sign = 1;
                else sign = -1;
            }
            ptr = end + 1;
        }
        return f.standarize().serialize();
    }
};

int main(){
    Solution s;
    string ans = s.fractionAddition("-1/2+1/2+1/3");
    cout << ans << endl;
    return 0;
}