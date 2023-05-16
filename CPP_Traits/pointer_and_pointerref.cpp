/*
 * @author: Zhexuan Gu
 * @Date: 2023-05-16 16:19:12
 * @LastEditTime: 2023-05-16 16:28:51
 * @FilePath: /CPPprojects/Leetcode/CPP_Traits/pointer_and_pointerref.cpp
 * @Description: Please implement
 */
#include <iostream>
using namespace std;

struct Node
{
    int _data;
    Node* next;
    Node():_data(0), next(nullptr){};
    Node(int val):_data(val), next(nullptr){};
    Node(const Node& node):_data(node._data), next(node.next){};
};

void insert_to_list(Node* &head, int val){
    /*
    当用引用时，我们相当于直接修改了此处的head.
    不用引用的话，我们函数参数里的head仅仅是原指针的一个copy，即使修改了也不会对原指针产生影响。
    所以加不加引用决定了，你的这个新的 val 节点究竟加不加得进去
    */
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void show_list(Node* h){
    while(h){
        cout << h->_data << " ";
        h = h->next;
    }
    cout << endl;
}


int main(){
    Node* head = new Node(5);
    Node* p1 = new Node(23);
    Node* p2 = new Node(24);
    head->next = p1;
    p1->next = p2;
    insert_to_list(head->next, 88);
    show_list(head);
    return 0;
}