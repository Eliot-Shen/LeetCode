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
    vector<int> postorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* h){
        if(h != NULL){
            stack<TreeNode*> s;
            s.push(h);
            // h为上一次打印的结点，如果没有打印过结点，h就为头结点
            while(!s.empty()){
                TreeNode* cur = s.top();
                if(cur->left != NULL && h != cur->left && h != cur->right){
                    //有左子树且左子树没有被处理过
                    s.push(cur->left);
                }else if(cur->right != NULL && h!= cur->right){
                    //有右子树且右子树没有被处理过
                    s.push(cur->right);
                }else{
                    //没有左树右树 或者都被处理过了
                    ans.push_back(cur->val);
                    h = s.top();
                    s.pop();
                }
            }
        }
    }
};