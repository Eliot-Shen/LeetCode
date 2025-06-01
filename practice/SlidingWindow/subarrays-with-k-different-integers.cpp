#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    int MAXN = 20001;
    vector<int> cnts;   
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        cnts.resize(MAXN);
        return numsOfMostKinds(nums, k) - numsOfMostKinds(nums,k-1);
    }
    // 弱条件：arr中有多少子数组，数字种类不超过k
    int numsOfMostKinds(vector<int>arr, int k){
        fill(cnts.begin(), cnts.end(), 0); // fflush the cnts for different k
        int ans = 0;
        for(int l=0,r=0,collect=0; r<arr.size(); r++){
            if(++cnts[arr[r]]==1) collect++;
            while(collect > k){//数字种类超过k种
                if(--cnts[arr[l++]] == 0) collect--;
            }
            ans += r-l+1;
        }
        return ans;
    }
};