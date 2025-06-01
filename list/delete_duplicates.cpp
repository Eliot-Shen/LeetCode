#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 1,cur = 1;
        for(int i=1;i<nums.size();i++){
            while(i<nums.size()&&nums[i]==nums[i-1]){
                //注意i越界问题，还有考虑&&的短路效应，判断越界应该在前
                i++;
            }
            cur = i;
            if(cur<nums.size()){
                nums[pre] = nums[cur];
                pre++;
            }
        }
        return pre;
    }
};