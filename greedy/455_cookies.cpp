#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int left = 0,right = 0;
        int sum = 0;
        while(left<g.size()&&right<s.size()){
            if(g[left]<=s[right]){
                sum++;
                left++;
                right++;
            }else{
                right++;
            }
        }
        return sum;
    }
};