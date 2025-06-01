#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        int pre = -1;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==1){
                if(pre<0){
                    sum += i/2;
                    
                }else{
                    sum += (i-pre)/2-1;
                }
                pre = i;
            }
        }
        if(pre<0){
            sum += (flowerbed.size()+1)/2;
        }else{
            sum += (flowerbed.size()-pre-1)/2;
        }
        return sum>=n;
    }
};

//解法2：填充数组
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        int pre = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i=1;i+1<flowerbed.size();i++){
            if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0){
                flowerbed[i] = 1;
                sum++;
            }
        }
        return sum>=n;
    }
};