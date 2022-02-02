// N皇后十一个老掉牙但又很经典的回溯法的题目了，不再具体解释题目含义了
// Q51
// 本题中主要是输出格式会有点神奇
// 以四皇后为例，输出是这样的   -----》 且最后要求返回所有满足的情况
/*
 [.Q..]
 [...Q]
 [Q...]
 [..Q.]
*/


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    void backtrack(vector<vector<bool>>& visited, int n, vector<string>& vec, int row){
        if(row == n){
            ans.push_back(vec);
            return;
        }
        for(int i = 0 ; i < n ; i ++){
            if(!visited[row][i]){
                vector<pair<int, int>> take_up;
                visited[row][i] = true;
                for(int j = row + 1 ; j < n ; j ++){
                    for(int k = 0 ; k < n ; k ++){           // take up those invalid positions
                    // 条件如果不加 !visited的话，有几对值会被重复放入(就是多次不合法)
                    // 那么回退的时候可能修改回false了，其实仍应该保持true了，因为其对更前轮次的行来说依旧不合法！
                        if(k == i && !visited[j][k]){                          // in the same col
                            take_up.push_back({j, k});
                            visited[j][k] = true;
                        }
                        else if(abs(j - row) == abs(k - i) && !visited[j][k]){ // in dui jiao
                            take_up.push_back({j ,k});
                            visited[j][k] = true;
                        }
                    }
                }
                vec[row][i] = 'Q';
                backtrack(visited, n, vec, row + 1);
                vec[row][i] = '.';
                for(auto obj : take_up){
                    visited[obj.first][obj.second] = false;
                }
                visited[row][i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        vector<string> vec(n, str);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(visited, n, vec, 0);
        return ans;
    }
};

int main(){
    Solution s;
    s.solveNQueens(5);
    return 0;
}