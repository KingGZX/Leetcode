#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    string ans = "";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root){
            ans += to_string(root->val);
            ans += " ";
            serialize(root->left);
            if(!root->left)
                ans += "# ";
            serialize(root->right);
            if(!root->right)
                ans += "# ";
        }
        return ans;
    }

    TreeNode* helper(istringstream& ss){
        /*
        ss 是由serialize返回的字符串转换得来的流，它可以以空格为界限每次读一个string到sub中，然后再用string->to->integer stoi
        转换成int构造树节点
        */
        string sub;
        ss >> sub;
        if(sub == "#")return nullptr;
        int val = stoi(sub);
        TreeNode* root = new TreeNode(val);
        root->left = helper(ss);
        root->right = helper(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        istringstream temp(data);
        TreeNode* root = helper(temp);
        return root;
    }
};

// 单纯调用 string 的系列API导致运行时间很长，击败也仅能 双5%
// 所以大家用了一个trick就是不用字符串，直接用vector
class Codec2 {
public:
    vector<int> tmp;
    int minm = INT32_MIN;
    // Encodes a tree to a single string.
    
    void preorder(TreeNode* root) {
        if(root){
            tmp.push_back(root->val);
            preorder(root->left);
            if(!root->left) tmp.push_back(minm);
            preorder(root->right);
            if(!root->right) tmp.push_back(minm);
        }
    }
    
    string serialize(TreeNode* root) {
        preorder(root);
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = tmp.size();
        int cnt = 0;
        return helper(cnt, n);
    }

    TreeNode* helper(int& cnt, int n) {
        if(cnt >= n || tmp[cnt] == minm) return nullptr;
        TreeNode* root = new TreeNode(tmp[cnt]);
        cnt ++;
        root->left = helper(cnt, n);
        cnt ++;
        root->right = helper(cnt, n);
        return root;
    }
};



int main(){
    TreeNode* root = new TreeNode(-1);
    TreeNode* l1 = new TreeNode(0);
    TreeNode* r1 = new TreeNode(1);
    root->left = l1;
    root->right = r1;
    /*
    TreeNode* l2 = new TreeNode(4);
    TreeNode* r2 = new TreeNode(5);
    r1->left = l2;
    r1->right = r2;
    */
    Codec codec;
    string str = codec.serialize(root);
    cout << str << endl;
    codec.deserialize(str);
    return 0;
}