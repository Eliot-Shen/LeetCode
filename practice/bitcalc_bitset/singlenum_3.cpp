#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long eor1 = 0;
        for(int num:nums){
            eor1 ^= num;
        }
        long rightone = eor1 & (-eor1);
        vector<int> ans(2);
        int eor2 = 0;
        for(int num:nums){
            if((num & rightone) == 0){
                eor2 ^= num;
            }
        }
        ans[0] = eor2;
        ans[1] = eor1 ^ eor2;
        return ans;
    }
};