#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
private:
    const int MAXN = 301;
    int strlength;
    int sets;
    std::vector<int> father;
public:
    int numSimilarGroups(vector<string>& strs) {
        strlength = strs[0].length();
        int n = strs.size();
        build(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(find(i) == find(j)) continue;
                if(issimilar(i, j, strs))  unionset(i, j);
            }
        }
        return sets;
    }
    void build(int m){
        father.resize(MAXN);
        for(int i=0;i<m;i++){
            father[i] = i;
        }
        sets = m;
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
    bool issimilar(int x, int y, vector<string>& strs){
        int cnt = 0;
        for(int i=0;i<strlength && cnt < 3;i++){
            if(strs[x][i]!=strs[y][i]) cnt++;
        }
        return cnt == 2 || cnt == 0;
    }
    void unionset(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx!=fy){
            father[fx] = fy;
            sets--;
        }
    }
};