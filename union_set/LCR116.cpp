#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> ufs(isConnected.size(),-1);
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
        for(size_t i = 0;i<isConnected.size();i++)
        {
            for(size_t j = 0;j<isConnected[i].size();j++)
            {
                if (isConnected[i][j]==1)
                {
                    int root1 = findRoot(i);
                    int root2 = findRoot(j);
                    if(root1 == root2) continue;//重要！
                    if(ufs[root1] < ufs[root2]){
                        ufs[root1] += ufs[root2];
                        ufs[root2] = root1;
                    }else{
                        ufs[root2] += ufs[root1];
                        ufs[root1] = root2;
                    }
                }
               
            }
        }
		size_t size=0;
        for(int i =0;i<ufs.size();i++)
        {
            if (ufs[i]<0) ++size;
        }
        return size;
    }
};

