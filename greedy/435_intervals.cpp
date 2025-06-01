#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            return a[1] < b[1];
        });
        int total = 0,lastend = intervals[0][1];
        for(int i=1;i<n;i++){   
            if(lastend > intervals[i][0]){
                total++;
            }else{
                lastend = intervals[i][1];
            }
        }
        return total;
    }
};