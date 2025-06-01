#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int n;
    const int MAXN = 3e4 + 1;
    vector<int> father;
    vector<int> maxval;
    int cnt;
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        n = vals.size();
        cnt = n;
        build(n);
        sort(edges.begin(), edges.end(), [&](vector<int>e1, vector<int>e2){
            cout << e1[0] <<" "<< e1[1] << endl;
            int maxval1 = max(vals[e1[0]], vals[e1[1]]);
            int maxval2 = max(vals[e2[0]], vals[e2[1]]);
            return (maxval1 <= maxval2);
        });
        for(int i=0;i<edges.size();i++){
            cnt += unionset(edges[i][0], edges[i][1], vals);
        }
        return cnt;
    }
    void build(int n){
        father.resize(MAXN);
        maxval.resize(MAXN);
        for(int i=0;i<n;i++){
            father[i] = i;
            maxval[i] = 1;
        }
    }
    int find(int i){
        if(i != father[i]){
            i = find(father[i]);
        }
        return father[i];
    }
    int unionset(int a, int b, vector<int>& vals){
        int fx = find(a);
        int fy = find(b);
        int path = 0;
        if(vals[fx] > vals[fy]){
            father[fy] = fx;
        }else if(vals[fx] < vals[fy]){
            father[fx] = fy;
        }else{
            path = maxval[fx] * maxval[fy];
            maxval[fx] += maxval[fy];
            father[fy] = fx;
        }
        return path;
    }
};

int main(){
    Solution s;
    // vector<int> vals = {1,1,2,2,3};
    // vector<vector<int>> edges = {{0,1},{1,2},{2,3},{2,4}};
    vector<int> vals = {16, 20, 17, 17, 20, 18, 8, 15, 17, 20, 14, 9, 10, 3, 13, 3, 12, 19, 14, 9, 2, 0, 18, 8, 2, 14, 3, 14, 7, 4, 12, 14, 6, 3, 20, 8, 10, 19, 8, 14, 3, 19, 6, 12, 4, 20, 7, 19, 7, 17};
    vector<vector<int>> edges = {
    {0, 1}, {2, 0}, {3, 1}, {2, 4}, {5, 2}, {6, 5}, {7, 3}, {8, 5}, {9, 5},
    {4, 10}, {1, 11}, {12, 1}, {6, 13}, {0, 14}, {15, 11}, {0, 16}, {3, 17},
    {18, 1}, {2, 19}, {20, 14}, {0, 21}, {4, 22}, {23, 20}, {24, 13}, {25, 20},
    {26, 11}, {22, 27}, {18, 28}, {29, 27}, {30, 9}, {31, 29}, {5, 32}, {33, 27},
    {34, 30}, {35, 4}, {1, 36}, {37, 35}, {26, 38}, {39, 22}, {19, 40}, {7, 41},
    {5, 42}, {43, 36}, {11, 44}, {45, 42}, {46, 34}, {20, 47}, {37, 48}
    };
    cout << s.numberOfGoodPaths(vals, edges);
}