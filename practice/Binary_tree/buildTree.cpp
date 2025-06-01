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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> node;
        for(int i=0; i<inorder.size(); i++){
            node[inorder[i]] = i;
        }
        return f(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, node);
    }
    TreeNode* f(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2, map<int,int> node){
        if(l1 > r1){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[l1]);
        int rootplace = node[root->val];
        root->left = f(preorder, l1+1, l1+rootplace-l2, inorder, l2, rootplace-1, node);
        root->right = f(preorder, l1+rootplace-l2+1, r1, inorder, rootplace+1, r2, node);
        return root;
    } 
};