#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Trie{
    // static array version
    public:
        static const int MAXN = 1000;
        int tree[MAXN][26];
        int end[MAXN];
        int pass[MAXN];
        int cnt;

        void build(){ //别忘了先build
            cnt = 1;
            for(int i = 0; i <= MAXN; i++){
                fill_n(tree[i], 26, 0); // 初始化每一行
                end[i] = 0;
                pass[i] = 0;
            }
        }
        void insert(string word){
            int cur = 1;
            pass[cur]++;
            for(int i=0, path; i<word.length(); i++){
                path = word[i] - 'a';
                if(tree[cur][path]==0){
                    tree[cur][path] = ++cnt;
                }
                cur = tree[cur][path];
                pass[cur]++;
            }
            end[cur]++;
        }
        int search(string word){
            int cur = 1;
            for(int i=0, path; i<word.length(); i++){
                path = word[i] - 'a';
                if(tree[cur][path] == 0){
                    return 0;
                }
                cur = tree[cur][path];
            }
            return end[cur];
        }
        int prefixnumber(string word){
            int cur = 1;
            for(int i=0, path; i<word.length(); i++){
                path = word[i] - 'a';
                if(tree[cur][path] == 0){
                    return 0;
                }
                cur = tree[cur][path];
            }
            return pass[cur];
        }
        void del(string word){
            if(search(word)>0){
                int cur = 1;
                for(int i=0, path; i<word.length(); i++){
                    path = word[i] - 'a';
                    if(--pass[tree[cur][path]] == 0){//这里顺带着--pass了
                        tree[cur][path] = 0;
                        return ;
                    }
                    cur = tree[cur][path];
                }
                end[cur]--;
            }
        }
        void clear(){
            for(int i=1;i<=cnt;i++){
                end[i] = 0;
                pass[i] = 0;
                fill_n(tree[i], 26, 0);
            }
        }

};

// class Trie{
//     struct TrieNode{
//         int pass;
//         int end;
//         vector<TrieNode*> nexts;

//         TrieNode(){
//             pass = 0;
//             end = 0;
//             nexts.resize(26);
//         }
//     };
//     private:
//         TrieNode* root;
//     public:
//         Trie(){
//             root = new TrieNode();
//         }
//         void insert(string word){
//             TrieNode* node = root;
//             node->pass++;
//             for(int i=0, path; i<word.length(); i++){
//                 path = word[i] - 'a';
//                 if(node->nexts[path] == NULL){
//                     node->nexts[path] = new TrieNode();
//                 }
//                 node = node->nexts[path];
//                 node->pass++;
//             }
//             node->end++;
//         }
//         int search(string word){
//             TrieNode* node = root;
//             for(int i=0, path; i<word.length(); i++){
//                 path = word[i] - 'a';
//                 if(node->nexts[path] == NULL){
//                     return 0;
//                 }
//                 node = node->nexts[path];
//             }
//             return node->end;
//         }
//         int prefixNumber(string prefix){
//             TrieNode* node = root;
//             for(int i=0, path; i<prefix.length(); i++){
//                 path = prefix[i] - 'a';
//                 if(node->nexts[path] == NULL){
//                     return 0;
//                 }
//                 node = node->nexts[path];
//             }
//             return node->pass;
//         }
//         void del(string word){
//             if(search(word) > 0){
//                 TrieNode* node = root;
//                 node->pass--;
//                 for(int i=0, path; i<word.length(); i++){
//                     path = word[i] - 'a';
//                     if(--(node->nexts[path]->pass) == 0){
//                         node->nexts[path] = NULL;
//                         free(node->nexts[path]);
//                         return;
//                     }
//                     node = node->nexts[path];
//                 }
//                 node->end--;
//             }
//         }
// };

int main(){
    Trie tree;
    tree.build();
    tree.insert("apple");
    cout << tree.search("apple");
    tree.del("apple");
    tree.clear();
}

//leetcode
// class Trie {
//     struct TrieNode{
//         public:
//             int pass;
//             int end;
//             vector<TrieNode*> nexts;

//             TrieNode(){
//                 pass = 0;
//                 end = 0;
//                 nexts.resize(26);
//             }
//     };
// private:
//     TrieNode* root;
// public:
//     Trie(){
//         root = new TrieNode();
//     }
    
//     void insert(string word) {
//         TrieNode* node = root;
//         node->pass++;
//         for(int i=0, path; i<word.length(); i++){
//             path = word[i] - 'a';
//             if(node->nexts[path] == NULL){
//                 node->nexts[path] = new TrieNode();
//             }
//             node = node->nexts[path];
//             node->pass++;
//         }
//         node->end++;
//     }
    
//     bool search(string word) {
//         TrieNode* node = root;
//         for(int i=0, path; i<word.length(); i++){
//             path = word[i] - 'a';
//             if(node->nexts[path] == NULL){
//                 return false;
//             }
//             node = node->nexts[path];
//         }
//         if(node->end > 0){
//             return true;
//         }
//         return false;
//     }
    
//     bool startsWith(string prefix) {
//         TrieNode* node = root;
//         for(int i=0, path; i<prefix.length(); i++){
//             path = prefix[i] - 'a';
//             if(node->nexts[path] == NULL){
//                 return 0;
//             }
//             node = node->nexts[path];
//         }
//         if(node->pass > 0){
//             return true;
//         }
//         return false;
//     }
// };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */