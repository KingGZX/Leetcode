/*
Q785
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。
形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：
1.不存在自环（graph[u] 不包含 u）。
2.不存在平行边（graph[u] 不包含重复值）。
3.如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
4.这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：
如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，
并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 。
 

示例 1：
输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
输出：false
解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。

示例 2：
输入：graph = [[1,3],[0,2],[1,3],[0,2]]
输出：true
解释：可以将节点分成两组: {0, 2} 和 {1, 3} 。
*/



#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    /*
    vec容器给每个结点的值代表把这个结点划分到哪一个集合，0代表未被遍历到。1 和 2 就分别代表两集合
    queue用于进行广度优先遍历
    思路就是：
        遍历到的结点如果未被访问过，就将其加入队列，并任意先分配进集合1
        然后就可以对这些未被遍历的结点访问其所有边：
            如果边另一端连接的结点未被遍历过就将它也放入队列并设置其为对立的集合
            如果边另一端连接的结点已经被遍历过了并且已经被划分成当前结点的相同集合则不是二分图
    */
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        queue<int> q;
        vector<int> vec(size, 0);
        for(int i = 0 ; i < size ; i ++){
            if(!vec[i]){
                q.push(i);
                vec[i] = 1;
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(const int& obj : graph[node]){
                    if(!vec[obj]){
                        q.push(obj);
                        vec[obj] = vec[node] == 2 ? 1 : 2;
                    }
                    else if(vec[node] == vec[obj]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    return 0;
}