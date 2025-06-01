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
    int MAXN = 101;
    vector<TreeNode*> queue;
    int l, r;
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        l = r = 0;
        queue.resize(MAXN);
        queue[r++] = root;
        bool leaf = false;//Whether has encountered with node with incomplete children
        while(l < r){
            TreeNode* head = queue[l++];
            if((head->left == NULL && head->right != NULL) || (leaf && (head->left != NULL || head->right != NULL))) {
                return false;
            }

            if(head->left != NULL){
                queue[r++] = head->left;
            }
            if(head->right != NULL){
                queue[r++] = head->right;
            }

            if(head->left == NULL || head->right == NULL){
                // do not have complete children
                leaf = true;
            }
        }
        return true;
    }
};
