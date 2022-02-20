/*
Q208
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 
示例：
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// 首先定义字典树结点：字典树头结点为空
struct TrieNode{
    // char ch;
    int prefix;  // 以某个结点即之前字符组成的 字符串 为前缀的字符串数量
    int count;  // 以某个结点结尾的字符串数量
    // 因为全是字符串，我们用字符的ASCII码作为z子节点下标
    TrieNode* next[26];
    TrieNode():prefix(0), count(0){memset(next, 0, sizeof(next));};
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        // 初始化头结点
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0 ; i < word.length() ; i ++){
            int index = word[i] - 'a';
            if(!temp->next[index]){
                TrieNode* p = new TrieNode;
                p->prefix ++;
                temp->next[index] = p;
            }
            temp = temp->next[index];
        }
        temp->count ++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // 题目已给出word不为空
        TrieNode* temp = root;
        for(int i = 0 ; i < word.size() ; i ++){
            int index = word[i] - 'a';
            if(!temp->next[index]) 
                return false;
            else
                temp = temp->next[index];
        }
        // 出来后不是万事大吉了，要看看以此字符结尾的字符串是否存在即定义好的count值
        if(temp->count) return true;   
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0 ; i < prefix.size() ; i ++){
            int index = prefix[i] - 'a';
            if(!temp->next[index]) 
                return false;
            else
                temp = temp->next[index];
        }
        return true;
    }
};

int main(){
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */
    cout << sizeof(TrieNode) << endl;
    return 0;
}