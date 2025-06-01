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
    int MAXN = 4001;
    vector<TreeNode*> queue; //遍历宽度
    vector<unsigned long long> queue2; //同步记录节点编号
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans = 1;
        if (root == NULL) return ans;

        queue.resize(MAXN);
        queue2.resize(MAXN);
        int l=0, r=0;
        queue[r] = root;
        queue2[r++] = 1;
        while (l<r) {
            int size = r - l;
            ans = max(ans, queue2[r-1] - queue2[l] + 1);
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = queue[l];
                unsigned long long id = queue2[l++];
                if (cur->left != NULL){
                    queue[r] = cur->left;
                    queue2[r++] = 2 * id;
                }
                if (cur->right != NULL) {
                    queue[r] = cur->right;
                    queue2[r++] = 2 * id + 1;
                }  
            }
        }
        return ans;
    }
};