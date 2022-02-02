/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，
其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

 

示例 1：


输入：isConnected = [[1,1,0],
                    [1,1,0],
                    [0,0,1]]
输出：2
示例 2：


输入：isConnected = [[1,0,0],
                    [0,1,0],
                    [0,0,1]]
输出：3
*/

#include <iostream>
#include <vector>
using namespace std;


/*
这里涉及了DFS的一个比较常见的、朴素的算法。
用一个主循环来计算需要遍历的DFS次数，其实就是数据结构里的求“连通分量”的算法。
简述：
    bool数组记录每个节点--->在这里指某一个“省”是否被遍历到过
    DFS辅助函数就是做正常的一次从一个特定节点出发的深度优先搜索，把路径上的所有节点bool值进行修改
    主函数统计总共调用DFS的次数，最后答案就是连通分量个数--->即“省份”的数量。
*/
class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, bool* flag, int cur, int size){
        flag[cur] = true;
        for (int i = 0; i < size; i ++){
            if(i != cur && isConnected[cur][i] && !flag[i]){
                DFS(isConnected, flag, i, size);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        bool *flag = new bool[cities];
        for (int i = 0; i < cities; i ++){
            flag[i] = false;
        }
        int ans = 0;
        for (int i = 0; i < cities; i ++){
            if(!flag[i]){
                DFS(isConnected, flag, i, cities);
                ans++;
            }
        }
        delete[] flag;
        return ans;
    }
};

int main(){
    return 0;
}