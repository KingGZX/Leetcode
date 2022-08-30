/*
Q998
最大树 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。

给你最大树的根节点 root 和一个整数 val 。

就像 之前的问题 那样，给定的树是利用 Construct(a) 例程从列表 a（root = Construct(a)）递归地构建的：

如果 a 为空，返回 null 。
否则，令 a[i] 作为 a 的最大元素。创建一个值为 a[i] 的根节点 root 。
root 的左子树将被构建为 Construct([a[0], a[1], ..., a[i - 1]]) 。
root 的右子树将被构建为 Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]) 。
返回 root 。
请注意，题目没有直接给出 a ，只是给出一个根节点 root = Construct(a) 。

假设 b 是 a 的副本，并在末尾附加值 val。题目数据保证 b 中的值互不相同。

返回 Construct(b) 。

 

示例 1：



输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：a = [1,4,2,3], b = [1,4,2,3,5]
示例 2：


输入：root = [5,2,4,null,1], val = 3
输出：[5,2,4,null,1,null,3]
解释：a = [2,1,5,4], b = [2,1,5,4,3]
示例 3：


输入：root = [5,2,3,null,1], val = 4
输出：[5,2,4,null,1,3]
解释：a = [2,1,5,3], b = [2,1,5,3,4]

*/


#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
提几个要点：
1.题目所要表达的建树规则，就是给出的根为root的树是用Q654的方法建立的。
比如给定数组[33， 50， 79， 40]，先找到最大的79，然后[33, 50]都成为79为根的左子树， [40]成为右子树。
然后再从其中找到较大的50作为左子树根，33作为50的左子结点。
40就成为79的右子树根。

2.现在新加入一个val元素，其实意义就是用[33, 50, 79, 40, val]来建树！！！

3.因此我分三种情况考虑，首先要提醒自己的是这个新加的值在末尾，一定往右搜索就行，绝对不可能成为其他结点的左子树！！
situation1： val比79都大，那么把val置为·新的根结点，原先的树变为val的左子树
situation2： val比40大，那么val成为79的右子树根结点，且把原先的根结点即40，挂到val的左子树上！
situation3:  val比40小，那么直接挂到40的右子树上即可。

可以对照代码，我描述的就是这三种情况！
*/
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root){
            if(val > root->val){
                TreeNode* node = new TreeNode(val);
                node->left = root;
                return node;
            }
            if(!root->right && val < root->val){
                root->right = new TreeNode(val);
            }
            else if(root->right){
                if(root->right->val < val){
                    TreeNode* node = new TreeNode(val, root->right, nullptr);
                    root->right = node;
                }
                else{
                    insertIntoMaxTree(root->right, val);
                }
            }
        }
        return root;
    }
};

int main(){
    return 0;
}