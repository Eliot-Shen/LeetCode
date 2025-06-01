#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> ufs(n,-1);
        auto findRoot = [&ufs](int x)
        {
            int root = x;
            while(ufs[root]>=0){
                root = ufs[root];
            }
            while(x != root){//压缩路径
                int t = ufs[x];
                ufs[x] = root;
                x = t;
            }
            return root;
        };
        for(size_t i = 0;i<edges.size();i++)
        {
            int root1 = findRoot(edges[i][0]);
            int root2 = findRoot(edges[i][1]);
            if(root1 == root2) continue;//重要！
            if(ufs[root1] < ufs[root2]){
                ufs[root1] += ufs[root2];
                ufs[root2] = root1;
            }else{
                ufs[root2] += ufs[root1];
                ufs[root1] = root2;
            }

        }
        int roots = findRoot(source);
        int rootd = findRoot(destination);
        if(roots==rootd) return true;
        else return false;
    }
};