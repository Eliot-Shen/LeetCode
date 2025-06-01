#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> last(256);
        fill(last.begin(), last.end(), -1);
        int ans = 0;
        for(int l=0,r=0;r<n;r++){
            l = max(l, last[s[r]] + 1);
            ans = max(ans, r - l + 1);
            last[s[r]] = r;
        }
        return ans;
    }
};