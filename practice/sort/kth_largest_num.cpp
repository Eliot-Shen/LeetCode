#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int first, last;
    int findKthLargest(vector<int>& nums, int k) {
        //第k大，排序后从左往右依次递增，那下标就为size-k
        return randomselect(nums, nums.size()-k);
    }
    int randomselect(vector<int>& nums, int i){
        int ans = 0;
        for(int l=0, r=nums.size()-1;l<=r;){
            partition(nums, l, r, nums[(l+r)/2]);// 只搜一侧
            if(i < first){
                r = first - 1;
            }else if(i > last){
                l = last + 1;
            }else{
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
    void partition(vector<int>& nums, int l, int r, int pivot){
        first = l;
        last = r;
        int i = l;
        while(i <= last){
            if(nums[i] == pivot){
                i++;
            }else if(nums[i] < pivot){
                swap(nums[first++], nums[i++]);
            }else{
                swap(nums[i], nums[last--]);
            }
        }
    }
};