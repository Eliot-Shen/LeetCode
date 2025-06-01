#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
private:
    const int MAXN = 100001;
    std::vector<int> father;
    int sets;
    int cols;
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        build(m, n, grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') continue;
                if(j<n-1 && grid[i][j+1] == '1'){
                    unionset(i, j, i, j+1);
                }
                if(i<m-1 && grid[i+1][j] == '1'){
                    unionset(i, j, i+1, j);
                }
            }
        }
        return sets;
    }
    void build(int m, int n, vector<vector<char>>& grid){
        cols = n;
        sets = 0;
        father.resize(MAXN);
        for(int i=0;i<m;i++){
            for(int j=0, idx;j<n;j++){
                if(grid[i][j]=='1'){ //初始有几个1就有几个集合
                    idx = index(i,j);
                    father[idx] = idx;
                    sets++;
                }
            }
        }
    }
    int index(int a, int b){
        return a*cols + b;
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
    void unionset(int a, int b, int c, int d){
        int fx = find(index(a, b));
        int fy = find(index(c, d));
        if(fx!=fy){
            father[fx] = fy;
            sets--;
        }
    }
};