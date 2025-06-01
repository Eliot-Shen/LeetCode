#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<2) return n;
        vector<int> num(n,1);
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1]){
                num[i] = num[i-1]+1;
            }
        }
        for(int i=n-1;i>0;--i){
            if(ratings[i] < ratings[i-1]){
                num[i-1] = max(num[i-1], num[i]+1);
            }
        }
        return accumulate(num.begin(),num.end(),0);
    }
};