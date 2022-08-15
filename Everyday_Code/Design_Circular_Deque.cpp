#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int t):val(t), next(nullptr), prev(nullptr){};
    Node(int t, Node* p1, Node* p2):val(t), next(p1), prev(p2){};
};

class MyCircularDeque {
private:
    Node* head;
    Node* tail;
    int size;
    int mmax;
public:
    MyCircularDeque(int k) {
        head = tail = nullptr;
        size = 0;
        mmax = k;
    }
    
    bool insertFront(int value) {
        if(!isFull()){
            size ++;
            if(!head){
                head = new Node(value);
                tail = head;
            }
            else{
                Node* temp = new Node(value, nullptr, head);
                head->next = temp;
                head = temp;
            }
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull()){
            size ++;
            if(!tail){
                tail = new Node(value);
                head = tail;
            }
            else{
                Node* temp = new Node(value, tail, nullptr);
                tail->prev = temp;
                tail = temp;
            }
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        Node* temp = head;
        if(size == 1)
            head = tail = nullptr;
        else{
            Node* newHead = head->prev;
            head = newHead;
        }
        delete temp;
        size --;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        Node* temp = tail;
        if(size == 1)
            head = tail = nullptr;
        else{
            Node* newTail = tail->next;
            tail = newTail;
        }
        delete temp;
        size --;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == mmax;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(){
    MyCircularDeque* obj = new MyCircularDeque(8);
    obj->insertFront(5);
    obj->getFront();
    obj->isEmpty();
    obj->deleteFront();
    obj->insertLast(3);
    obj->getRear();
    obj->insertLast(7);
    obj->insertFront(7);
    obj->deleteLast();
    obj->insertLast(4);
    obj->isEmpty();

}