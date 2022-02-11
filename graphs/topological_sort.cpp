#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
拓扑排序的概念：
    给定一张有向无环图，将所有结点排成一维线性阵列
    要求假如有一条边 i -> j，那么在阵列中i需要排在j之前

所以我们先寻找只有出度无入度的结点，输出此结点
然后把这个结点连接着的边的入度数减一
*/

void topo_sort(vector<vector<int>>& graph){
    queue<int> in_index;
    int node = graph.size();
    vector<int> in(node, 0);
    for(int i = 0 ; i < node ; i ++){
        for(const int& obj : graph[i]){
            in[obj] ++;
        }
    }
    for(int i = 0 ; i < node ; i ++){
        if(!in[i]){
            in_index.push(i);
        }
    }
    while(!in_index.empty()){
        int temp = in_index.front();
        in_index.pop();
        for(const int& obj : graph[temp]){
            if(--in[obj] == 0){
                in_index.push(obj);
            }
        }
        cout << temp << " ";
    }
    cout << endl;
}

void DFS(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& time, int node, stack<int>& order, int& cnt){
    visited[node] = true;
    for(const int& temp : graph[node]){
        if(!visited[temp]){
            DFS(graph, visited, time, temp, order, cnt);
        }
    }
    time[cnt ++] = node;    // time数组并不是去真实记录时间，而只是把率先弹出的栈帧结构那一结点放进来罢了
    order.push(node); 
}

void toposort_recursive_version(vector<vector<int>>& graph){
    /*
    递归算法：
        递归地对有向无环图进行深度优先搜索，求每个结点的结束时间    
        把结果按照结束时间从大到小进行输出就是拓扑排序的结果

        我们用栈这一数据结构来实现即DFS的最深结点应该最早退掉的栈帧结构
        (我们这里计时并不是说真的去记录clock or time)，从CSAPP角度来看"栈帧结构"

        递归的最深处应该是最早退栈的，所以"第几个退栈"，这个才是我们需要的"时间"
    */
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    vector<int> time(nodes, 0);
    stack<int> order;
    int cnt = 0;
    for(int i = 0 ; i < nodes ; i ++){
        if(!visited[i]){
            DFS(graph, visited, time, i, order, cnt);
        }
    }
    while(!order.empty()){
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;

    for(int i = 0 ; i < nodes ; i ++){
        cout << time[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<vector<int>> vec{{1}, {2}, {3}, {}};
    // topo_sort(vec);
    toposort_recursive_version(vec);
    return 0;
}