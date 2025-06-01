#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> ufs(26,-1);
        auto findroot = [&ufs](int x){
            while(ufs[x]>=0){
                x = ufs[x];
            }
            return x;
        };
        for(auto str:equations){
            if(str[1]=='='){
                int root1 = findroot(str[0]-'a');
                int root2 = findroot(str[3]-'a');
                if(root1!=root2){
                    ufs[root2] += ufs[root1];
                    ufs[root1] = root2;
                }
            }
        }
        for(auto str:equations){
            if(str[1]=='!'){
                int root1 = findroot(str[0]-'a');
                int root2 = findroot(str[3]-'a');
                if(root1 == root2){
                    return false;
                }
            }
        }
        return true;
    }
};