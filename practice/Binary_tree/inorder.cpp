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
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }
};
//preorder
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* head){
        if(head != NULL){
            stack<TreeNode*> s;
            s.push(head);
            while(!s.empty()){
                head = s.top();
                ans.push_back(head->val);
                s.pop();
                if(head->right){ //注意入栈顺序
                    s.push(head->right);
                }
                if(head->left){
                    s.push(head->left);
                }
            }
        }
    }
};