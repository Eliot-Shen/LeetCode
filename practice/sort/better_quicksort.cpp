#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class QuickSort{
public:
    int first,last;
    vector<int> nums;
    void quicksort(int l, int r){
        if(l >= r) return;
        partition(nums, l, r, nums[(l+r)/2]);
        int left = first;
        int right = last;
        quicksort(l, left-1);
        quicksort(right+1, r);
    }
    void partition(vector<int> nums, int l, int r, int pivot){
        first = l; //小于分支
        last = r; //大于分支
        int i=l;
        while(i<=last){
            if(nums[i]==pivot){
                i++;
            }else if(nums[i] < pivot){
                swap(nums[first++], nums[i++]);
            }else{
                swap(nums[last--], nums[i]);
            }
        }
    }
};
