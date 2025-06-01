#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32);
        fill(cnt.begin(),cnt.end(),0);
        for(int num:nums){
            for(int i=0;i<32;i++){
                cnt[i] += (num>>i)&1;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++){
            if(cnt[i] % 3 != 0){
                ans |= (1 << i);
            }
        }
        return ans;
    }
};