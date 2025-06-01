#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        vector<int> cnts(256);
        int ans = 0;
        for(int require = 1;require <= 26; require++){
            fill(cnts.begin(), cnts.end(), 0);
            // collect 窗口中一共收集到的种类数
            // satisfy 窗口中达标的种类数
            for(int l=0, r=0, collect = 0, satisfy = 0; r<n; r++){
                cnts[s[r]]++;
                if(cnts[s[r]]==1){
                    collect++;
                }
                if(cnts[s[r]]==k){
                    satisfy++;
                }
                // 种类超了
                while(collect > require){
                    if(cnts[s[l]]==1){
                        collect--;
                    }
                    if(cnts[s[l]]==k){
                        satisfy--;
                    }
                    cnts[s[l++]]--;
                }
                if(satisfy==require){
                    ans = max(ans, r-l+1);
                }
            }
        }
        return ans;
    }
};