#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Basic_Sort_Algorithms{
    private:
        vector<T> arrays_to_be_sort;
        vector<T> sorted_array;
    public:
        Basic_Sort_Algorithms<T>(const vector<T>& vec){arrays_to_be_sort = vec;};
        void show_sorted_arrays();

        void heapify(int loc, int len);    // 调整成大顶堆抑或小顶堆的标准格式
        void heapsort();   // 

        void merge();
        void merge_sort();
};

template<typename T>
void Basic_Sort_Algorithms<T>::show_sorted_arrays(){
    for(auto i : sorted_array){
        cout << i << " ";
    }
    cout << endl;
}

template<typename T>
void Basic_Sort_Algorithms<T>::heapify(int loc, int len){
    // heapify 的操作就是:
    // 从当前节点出发，以自己为根节点，看看自己的左右子节点是否需要和自己执行交换操作
    // 如果需要则交换 并且 变成自己交换过的子节点位置，如果不用交换则可以直接break
    // 此处我们假设构造大顶堆，即根节点应该比左右子节点都大！
    // int len = arrays_to_be_sort.size();
    for(int i = loc ; i < len ; ){
        int ptr = i * 2 + 1;    // left child
        if(ptr + 1 < len && arrays_to_be_sort[ptr] < arrays_to_be_sort[ptr + 1]){
            ptr ++;          // choose the bigger one from left & right child
        }
        if(ptr < len && arrays_to_be_sort[ptr] > arrays_to_be_sort[i]){   // need to swap
            swap(arrays_to_be_sort[ptr], arrays_to_be_sort[i]);
            i = ptr;    // 交换后，与根节点进行交换的左或右子树可能关系会发生改变，将指针重新指向交换的那个结点
        }
        else{
            break;
        }
    }
}

template<typename T>
void Basic_Sort_Algorithms<T>::heapsort(){
    // 初始化大顶堆
    int len = arrays_to_be_sort.size();
    // 从第一个非叶子结点开始不断往前调用heapify
    // heapify的功能就是以某结点为根节点的子树可以满足我们要构造的堆的要求
    // 逆序进行才能保证我们最大的结点值最后会被挂在整棵树的根节点
    // 如果顺序进行，根节点只会在左右孩子找最大值，但最大值并不一定刚好和根节点相连，最后一定会出错！
    for(int i = len / 2 - 1 ; i >= 0 ; i --){
        heapify(i, len);
    }
    // 交换根节点和最后一个元素的，然后继续调整堆，注意此时我们数组长度减一了，因为最大值已经被选出来了！
    int l(len);
    for(int i = 0 ; i < len ; i ++){
        sorted_array.push_back(arrays_to_be_sort[0]);
        // 其实不用任何操作，swap结束后本身 arrays_to_be_sort本身是一个递增的有序数组
        // 但用push_back后，其会反过来刚好变成递减的有序数组
        swap(arrays_to_be_sort[0], arrays_to_be_sort[--l]);
        heapify(0, l);
    }
    show_sorted_arrays();
}

int main(){
    vector<int> vec{99, 23, 77, 0, 12, 56, 3};
    Basic_Sort_Algorithms<int> t(vec);
    t.heapsort();
    return 0;
}