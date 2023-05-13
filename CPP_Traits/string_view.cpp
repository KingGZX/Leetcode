#include <iostream>
#include <string_view>
using namespace std;

string_view foo(){
    string temp{"nice"};
    // ----------------- warning ----------------//
    return string_view(temp);
}

/*
所以稍微总结一下string_view的优点：

1. 不用自己开内存分配，直接将指针指向数据域
2. 由于.data() 是const char* 类型的，string_view无法修改原数据
3. 注意生命周期问题，string_view的生命周期不能比他引用的东西来得长
*/

int main(){

    string_view s{"hello, world!", 5};
    cout << s << endl;
    cout << s.data() << endl;

    // 生命周期
    // 会有warning， 因为函数返回对象绑定的是temp的内存，但函数结束后，temp内存被释放，此时输出返回的对象，data()是一个空指针。
    cout << foo() << endl;
    return 0;
}