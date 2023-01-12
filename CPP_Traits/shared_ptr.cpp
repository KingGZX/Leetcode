/*
 * @author: Zhexuan Gu
 * @Date: 2022-09-21 13:58:01
 * @LastEditTime: 2023-01-11 21:08:31
 * @FilePath: /CPPprojects/Leetcode/CPP_Traits/shared_ptr.cpp
 * @Description: Please implement
 */
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <memory>

using namespace std;

class Solution{
    public:
        Solution(int i){cout << "我被创建啦\n";};
        ~Solution(){cout << "我被释放啦\n";};
};

int main(){
    // 创建智能指针就可以不用我们手动释放内存 很方便
    shared_ptr<Solution> ptr = make_shared<Solution>(5);
    Solution* obj = new Solution(5);
    return 0;
}