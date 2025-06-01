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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue.resize(MAXN);
        int l=0,r=0;
        queue[r++] = root;
        bool reverse = false;
        // false from left -> right, l...r-1, num of size 
        // true from right -> left, r-1...l, num of size
        while (l<r) {
            int size = r - l;
            vector<int> currentLevel;
            for(int i = reverse ? r-1 : l,j=reverse ? -1 : 1, k=0; k<size; i+=j, k++){
                TreeNode* cur = queue[i];
                currentLevel.push_back(cur->val);
            }
            for (int i = 0; i < size; ++i) { //正常宽度优先遍历
                TreeNode* cur = queue[l++];
                if (cur->left != NULL) queue[r++] = cur->left;
                if (cur->right != NULL) queue[r++] = cur->right;  
            }
            ans.push_back(currentLevel);
            reverse = !reverse;
        }
        return ans;
    }
};