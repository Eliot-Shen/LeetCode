#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int maxTotalReward(vector<int>& rewardValues) {
    vector<int> dp(4010,0);
    dp[0] = 1;
    sort(rewardValues.begin(),rewardValues.end());
    for(int i=0;i<rewardValues.size();i++){
        for(int j=4000;j>=0;j--){
            if(rewardValues[i]>j) dp[j+rewardValues[i]] |= dp[j];
        }
    }
    for(int j=4000;j>=0;j--) if(dp[j]) return j;
    return 0;
}

int main(){

}