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

class Solution {
public:
    int MAXN = 2001;
    vector<TreeNode*> queue; //数组模拟队列
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue.resize(MAXN);
        int l=0,r=0;
        queue[r++] = root;
        while (l<r) {
            int size = r - l;
            vector<int> currentLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* cur = queue[l++];
                currentLevel.push_back(cur->val);

                if (cur->left != NULL) queue[r++] = cur->left;
                if (cur->right != NULL) queue[r++] = cur->right;  
                
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (root == NULL) return ans;

//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             int size = q.size();
//             vector<int> currentLevel;

//             for (int i = 0; i < size; ++i) {
//                 TreeNode* cur = q.front();
//                 q.pop();
//                 currentLevel.push_back(cur->val);

//                 if (cur->left != NULL) q.push(cur->left);
//                 if (cur->right != NULL) q.push(cur->right);
//             }

//             ans.push_back(currentLevel);
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root!=NULL){
//             queue<TreeNode*> q;
//             map<TreeNode*, int> levels;
//             q.push(root);
//             levels[root] = 0;
//             while(!q.empty()){
//                 TreeNode* cur = q.front();
//                 int level = levels.at(cur);
//                 if(ans.size() == level){
//                     vector<int> ans1;
//                     ans.push_back(ans1);
//                 }
//                 ans.at(level).push_back(cur->val);
//                 if(cur->left != NULL){
//                     q.push(cur->left);
//                     levels[cur->left] = level+1;
//                 }
//                 if(cur->right != NULL){
//                     q.push(cur->right);
//                     levels[cur->right] = level+1;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 0;
//         vector<int> anslevel;
//         while(!q.empty()){
//             int cnt = 1;
//             while(cnt <= pow(2, level)){
//                 TreeNode* cur = q.front();
//                 anslevel.push_back(cur->val);
//                 if(cur->left != NULL)   q.push(cur->left);
//                 if(cur->right != NULL)   q.push(cur->right);
//                 q.pop();
//                 cnt++;
//             }
//             level++;
//             ans.push_back(anslevel);
//             anslevel.clear();
//         }
//         return ans;
//     }
// };