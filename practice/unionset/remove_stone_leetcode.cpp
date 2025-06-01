#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
private:
    const int MAXN = 1001;
    std::vector<int> father;
    std::unordered_map<int,int> rowmap;
    std::unordered_map<int,int> colmap;
    int sets;
    int n;
public:
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        build();
        for(int i=0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1];
            auto itx = rowmap.find(x);
            auto ity = colmap.find(y);
            if(itx == rowmap.end()){
                rowmap.insert({x,i});
            }else{
                unionset(i, itx->second);
            }
            if(ity == colmap.end()){
                colmap.insert({y,i});
            }else{
                unionset(i, ity->second);
            }
        }
        return n - sets;
    }
    void build(){
        father.resize(MAXN);
        rowmap.clear();
        colmap.clear();
        for(int i=0;i<n;i++){
            father[i] = i;
        }
        sets = n;
    }
    int find(int i){
        if(i != father[i]){
            i = find(father[i]);
        }
        return father[i];
    }
    bool issameset(int x, int y){
        return find(x) == find(y);
    }
    void unionset(int a, int b){
        int fx = find(a);
        int fy = find(b);
        if(fx!=fy){
            father[fx] = fy;
            sets--;
        }
    }
};