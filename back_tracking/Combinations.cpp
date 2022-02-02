/*
Q77
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
*/


#include <iostream>
#include <vector>
using namespace std;


// 此算法已经是最优解，但仍然只是击败60%的人
// 这时我们从代码层面，或者说C++内核、更底层方面来进行考虑
// 我们的push_back 和 pop_back是耗时操作，我们在Solution2中给出另外一种写法
class Solution {
public:
  vector<vector<int>> ans;
  vector<int> temp;
  void backtrack(int n, int k, vector<bool>& traverse, int cur){
      if(temp.size() == k){
        ans.push_back(temp);
        return;
      }
      for(int i = cur ; i <= n ; i ++){
        temp.push_back(i);
        backtrack(n, k, traverse, i + 1);
        temp.pop_back();
      }
  }
  vector<vector<int>> combine(int n, int k) {
      vector<bool> traverse(n + 1, false);
      backtrack(n, k, traverse, 1);
      return ans;
  }
};


// 改为用指针配合修改某块内存的值的方式可以提高10%的击败率，也算是一种改良方式
class Solution2 {
public:
  vector<vector<int>> ans;
  void backtrack(int n, int k, vector<bool>& traverse, vector<int>& temp, int cur, int& ptr){
      if(ptr == k){
        ans.push_back(temp);
        return;
      }
      for(int i = cur ; i <= n ; i ++){
        temp[ptr ++] = i;
        backtrack(n, k, traverse, i + 1);
        ptr --;
      }
  }
  vector<vector<int>> combine(int n, int k) {
      vector<bool> traverse(n + 1, false);
      vector<int> temp(k, 0);
      int ptr = 0;
      backtrack(n, k, traverse, 1);
      return ans;
  }
};



int main(){
  return 0;
}
