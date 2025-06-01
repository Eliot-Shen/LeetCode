#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int sum = 0;
        vector<int> rowMax(n);
        vector<int> colMax(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowMax[i] = max(rowMax[i],grid[i][j]);
                colMax[j] = max(colMax[j],grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int m = min(rowMax[i],colMax[j]);
                sum += m;
                grid[i][j] = m;
            }
        }
        return sum;
    }
};

