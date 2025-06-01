#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        //窗口范围[l,r)
        for(int l=0, r=0, sum;l<n;l=r+1,r=l){ 
            // l=r+1,因为r之前的净值一定为负，所以无法绕一圈，直接跳过这些出发点
            //l=r+1,r=l,r与l再次到同一位置
            // r%n表示扩充数组
            sum = 0;
            while(sum + gas[r%n] - cost[r%n] >= 0){
                if(r - l == n){
                    return l;
                }
                sum += gas[r%n] - cost[r%n];
                r++;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for(int l=0,r=0,len=0,sum=0;l<n;l++){
//             while(len < n && sum>=0){
//                 r = (l + (len++)) % n;
//                 sum += gas[r] - cost[r];
//             }
//             if(sum >= 0 ) return l;
//             else{
//                 len--;
//                 sum -= gas[l] - cost[l]; 
//                 //维护滑动窗口，仅改变起点，减少重复计算
//             }
//         }
//         return -1;
//     }
// };