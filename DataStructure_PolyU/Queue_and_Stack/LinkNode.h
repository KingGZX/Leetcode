/*
 * @author: Zhexuan Gu
 * @Date: 2022-09-21 15:32:18
 * @LastEditTime: 2022-09-21 19:24:09
 * @FilePath: /CPPprojects/Leetcode/DataStructure_PolyU/Queue_and_Stack/LinkNode.h
 * @Description: a simple node definition
 */
#include <iostream>
using namespace std;
namespace gzx_simple_stl{
    template <typename T>
    struct LinkNode{
        /* data */
        T _data;
        LinkNode<T>* next;
        LinkNode(T data):_data(data), next(nullptr){}
        LinkNode(T data, LinkNode<T>* nextptr):_data(data), next(nextptr){}
        LinkNode<T> operator=(LinkNode<T>* tempPtr){
            this->_data = tempPtr->_data;
            this->next = tempPtr->next;
            return *this;
        };
    };
};
