#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(n < t.length()) return "";

        vector<int> stats(256);
        fill(stats.begin(), stats.end(), 0);
        for(auto cha:t){
            stats[cha]--;
        }

        int start = 0;//where the shortest substring was found
        int len = n + 1;

        for(int l=0, r=0, debt = t.length(); r<n; r++){
            if(stats[s[r]]++ < 0) debt--;
            if(debt == 0){
                while(stats[s[l]] > 0){
                    stats[s[l]]--;
                    l++;
                }
                if(len > r - l + 1){
                    start = l;
                    len = r - l + 1;
                }
            }
        }
        return len == n+1 ? "" : s.substr(start, len);
    }
};