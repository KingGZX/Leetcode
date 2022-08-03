#include <iostream>
using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(int val){
        this->next = nullptr;
        this->val = val;
    };
};


class MyCircularQueue {
private:
    ListNode* head;
    ListNode* tail;
    int capacity;
    int size;   // 当前数量
public:
    MyCircularQueue(int k) {
        head = nullptr;
        tail = nullptr;
        capacity = k;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        ListNode* temp = new ListNode(value);
        if(!head)
            head = tail = temp;
        else{
            tail->next = temp;
            tail = tail->next;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        ListNode* temp = head;
        head = head->next;
        delete temp;
        size --;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return head->val;
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(size == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(size == capacity)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){
    return 0;
}