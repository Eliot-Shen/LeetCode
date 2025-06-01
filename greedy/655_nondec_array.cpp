#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int x = nums[i];
            int y = nums[i+1];
            if(x>y){
                nums[i] = y;
                if(is_sorted(nums.begin(),nums.end())){
                    return true;
                }
                nums[i] = x;
                nums[i+1] = x;
                return is_sorted(nums.begin(),nums.end());
            }
        }
        return true;
    }
};