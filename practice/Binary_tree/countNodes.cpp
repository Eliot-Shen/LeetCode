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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return f(root, 1, mostleft(root, 1));
    }   
    int f(TreeNode* cur, int level, int h){
        //level is where the cur at
        if(level == h) return 1;
        if(mostleft(cur->right, level+1) == h){
            return (1 << (h - level)) + f(cur->right, level+1, h);
        }else{
            return (1 << (h - level - 1)) + f(cur->left, level+1, h);
        }
    }
    int mostleft(TreeNode* cur, int level){
        while(cur != NULL){
            level++;
            cur = cur->left;
        }
        return level - 1;
    }
};