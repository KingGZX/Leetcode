/*
 * @author: Zhexuan Gu
 * @Date: 2023-06-23 13:15:19
 * @LastEditTime: 2023-06-23 13:29:30
 * @FilePath: /CPPprojects/Leetcode/CPP_Traits/move_semantic_ext.cpp
 * @Description: Please implement
 */
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Object {
public:
    string _str;

    explicit Object(string str): _str(std::move(str)) {
        std::cout << "build this object, address: " << this << endl;
    }

    virtual ~Object() {
        std::cout << "destruct this object, address: " << this << endl;
    }

    Object(const Object &object) : _str(object._str) {
        std::cout << "copy this object, address: " << this << endl;
    }

    Object(const Object &&object) noexcept: _str(std::move(object._str)) {
        std::cout << "move this object, address: " << this << endl;
    }
};

void f_copy(Object obj) {
    std::cout << "copy function, address: " << &obj << endl;
}

void f_move(Object &&obj) {
    // Object a_obj(std::move(obj));
    Object a_obj(std::move(obj));
    std::cout << "move function, address: " << &a_obj << endl;
}

int main() {
    Object obj("abc");

    // function calling
    f_copy(obj);
    f_move(std::move(obj));

    // std::cout << obj._str << endl;      // danger

    std::cout << "============ end ============" << endl;

    return 0;
}