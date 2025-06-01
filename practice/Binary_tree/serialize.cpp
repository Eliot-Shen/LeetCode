#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right); 
    }

    TreeNode* mydeserialize(istringstream &ss ){
        string tmp;
        ss >> tmp;
        if(tmp == "#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(tmp));
        root->left = mydeserialize(ss);
        root->right = mydeserialize(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return mydeserialize(ss);
    }
};
// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string interdata = "";
//     string serialize(TreeNode* root) {
//         if(root == NULL){
//             interdata += "#,";
//         }else{
//             interdata += to_string(root->val) + ",";
//             serialize(root->left);
//             serialize(root->right);
//         }
//         return interdata;
//     }
//     std::vector<string> stringToVector(const std::string& str) {
//         std::vector<string> vec;
//         std::istringstream iss(str);
//         std::string token;
        
//         while (std::getline(iss, token, ',')) {
//             vec.push_back(token); // 将字符串转换为整数
//         }
        
//         return vec;
//     }
//     int cnt;
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         vector<string> nodelist = stringToVector(data);
//         cnt = 0;
//         return g(nodelist);

//     }
//     TreeNode* g(vector<string>& nodelist){
//         string cur = nodelist[cnt++];
//         if(cur == "#"){
//             return NULL;
//         }else{
//             TreeNode* head = new TreeNode(stoi(cur));
//             head->left = g(nodelist);
//             head->right = g(nodelist);
//             return head;
//         }
//     }
// };
