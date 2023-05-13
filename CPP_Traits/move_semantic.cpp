/*
 * @author: Zhexuan Gu
 * @Date: 2022-09-21 13:58:01
 * @LastEditTime: 2023-05-13 16:08:16
 * @FilePath: /CPPprojects/Leetcode/CPP_Traits/move_semantic.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>

using namespace std;

class Str{
    class ch{
        private:
            int a;
        public:
            ch(const int& m):a(m){};
    };
public:
    shared_ptr<ch> internal_t;
    Str(const int& t):internal_t(make_shared<ch>(t)){};
    /*
    查看输出后可以发现，other作为一个右值在执行move后会变为nullptr.
    */
    Str(shared_ptr<ch> other):internal_t(std::move(other)){cout << "after moving:" << other << endl;};
    // Str(shared_ptr<ch> other):internal_t(other){cout << "after construction:" << other << endl;};
};

int main()
{
    Str p(1);
    cout << p.internal_t << endl;
    Str m(p.internal_t);
    cout << m.internal_t << endl;

    /*
    ------------------------- Notation --------------------------
    总之，在没有右值引用之前，我们调用一些拷贝构造或者拷贝赋值函数时。
    由于我们不想改变原参数，我们在拷贝指针时需要深拷贝，swap操作则会涉及了一系列new delete操作。

    但现在多了右值引用这一选项 "&&"，因此我们可以用移动构造和移动赋值函数。
    这时我们不再那么麻烦了，我们可以让新对象或待更新的对象直接占用右值的空间。
    同时将右值的指针置为null,否则新对象和右值指针指向同一区域，右值析构后那片区域就被释放了。通过设置nullptr，阻止释放空间。

    move的最大功能就是把传入的参数变为 右值引用 类型。

    移动语义大大加速了代码。
    */

    /*
    int* temp = new int(23);
    cout << temp << endl;
    int* ptr(std::move(new int(34)));
    cout << "after moving: " << temp << endl;
    cout << ptr << endl;
    */
    return 0;
}