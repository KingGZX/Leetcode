/*
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，
其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。
如果不可能完成所有课程，返回 一个空数组 。
 

示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：[0,1]
解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。

示例 2：
输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出：[0,2,1,3]
解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。

示例 3：
输入：numCourses = 1, prerequisites = []
输出：[0]
*/





#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // 可以实现但效率不高
    // 首先空间复杂度上就已经占用太多额外内存的，记录入度的数组in
    // 记录边连接情况为了方便操作减掉入度的数组link   O(n²)
    // 队列
    // 时间复杂度应该是O(n²)

    // 一种简单改进措施就是放弃link这个bool数组，先开辟一个
    // vector<vector<int>> link(numCourses, vector<int>())
    // 然后在遍历graph的时候 直接  link[obj[1]].push_back(obj[0])把与此结点连接的结点加入数组即可
    // 然后略微修改减度数那个循环即可，不难，不另写代码，效率提高不少

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 借鉴的就是我们topological_sort的思想 0入度就说明无先修课程
        vector<int> ans;
        vector<int> in(numCourses, 0);
        vector<vector<bool>> link(numCourses, vector<bool>(numCourses, false));
        int num = numCourses;   // 计数 看看最后是不是能全修完
        for(const vector<int>& obj : prerequisites){
                link[obj[1]][obj[0]] = true;
                in[obj[0]] ++;
        }
        queue<int> in_index;
        for(int i = 0 ; i < numCourses ; i ++){
            if(!in[i]){
                in_index.push(i);
            }
        }
        while(!in_index.empty()){
            num --;
            int temp = in_index.front();
            ans.push_back(temp);
            in_index.pop();
            for(int i = 0 ; i < numCourses ; i ++){
                if(link[temp][i]){
                    if(--in[i] == 0){
                        in_index.push(i);
                    }
                    link[temp][i] = false;
                }
            }
        }
        vector<int> empty;
        return num == 0 ? ans : empty;
    }


};

int main(){
    vector<vector<int>> vec{{1, 0}};
    Solution s;
    s.findOrder(2, vec);
    return 0;
}