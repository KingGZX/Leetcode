/*
 * @author: Zhexuan Gu
 * @Date: 2022-09-21 15:37:05
 * @LastEditTime: 2022-09-21 20:50:51
 * @FilePath: /CPPprojects/Leetcode/DataStructure_PolyU/Queue_and_Stack/myStack.h
 * @Description: a simple definition of stack
 */
#ifndef _MYSTACK_H_J
#define _MYSTACK_H_J
#include "LinkNode.h"

//using namespace gzx_simple_stl;

namespace gzx_simple_stl{
    template<typename T>
    class MyStack
    {
    private:
        /* data */
        LinkNode<T>* _top;
        int _capacity;
        int _maximum;
        // for the array based situation, left to be done
    public:
        MyStack(int capacity);
        MyStack(LinkNode<T>* head, int capacity);
        MyStack(const MyStack<T>& anotherStack);
        ~MyStack();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        bool Push(T data);
        bool Pop(T& data);
        // copy function
        void Copy(MyStack<T> oldStack, MyStack<T>& copy);
    };
};

#endif