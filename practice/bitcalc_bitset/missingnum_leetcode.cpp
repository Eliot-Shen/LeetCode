#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int eorall = 0, eorhas = 0;
        for(int i=0;i<nums.size();i++){
            eorall ^= i;
            eorhas ^= nums[i];
        }
        eorall ^= nums.size();
        return eorall ^ eorhas;
    }
};