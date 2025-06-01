#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l=0, r=0;
        int n = nums.size();
        int ans = n+1;
        while(r<n){
            sum += nums[r];
            //add one element every time
            while(sum - nums[l] >= target){
                sum -= nums[l++];
            }
            if(sum >= target) ans = min(ans, r-l+1);
            r++;
        }
        return ans == n+1 ? 0 : ans;
    }
};