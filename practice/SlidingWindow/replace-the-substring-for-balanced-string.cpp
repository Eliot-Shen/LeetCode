#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        vector<int> s(n);
        vector<int> cnts(4);
        for(int i=0;i<n;i++){
            char c = s.at(i);
            s[i] = (c == 'W' ? 1 : (c == 'E' ? 2 : (c=='R' ? 3 : 0 )));
            cnts[s[i]]++;
        }
        int debt = 0;
        for(int i=0;i<4;i++){
            if(cnts[i] < n/4){
                cnts[i]=0;
            }else{
                cnts[i] = n/4 - cnts[i];
                debt -= cnts[i];
            }
        }
        if(debt == 0) return 0;
        int ans = n+1;
        for(int l=0,r=0;r<n;r++){
            if(cnts[s[r]]++ < 0){
                debt--;
            }
            if(debt == 0){//该子串内有所有的欠债字符了
                while(cnts[s[l]] > 0){
                    // ==0的都是欠债的字符，>0的是不欠债字符，所以可以清除
                    cnts[s[l++]]--;
                }
                ans = min(ans, r-l+1);
            }
            
        }
        return ans;
    }
};