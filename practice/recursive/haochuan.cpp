#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int is(vector<char> path, int l, int r){
    while(l < r){
        if(path[l] != path[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int f(vector<char> path, int i){
    if(i == path.size()){
        int cnt = 0;
        for(int l=0;l<path.size();l++){
            for(int r=l+1;r<path.size();r++){
                if(is(path, l, r)){
                    cnt++;
                }
                if(cnt > 1){
                    return 0;
                }
            }
        }
        // for(auto element:path){
        //     cout << element;
        // }
        // cout << endl;
        return cnt == 1 ? 1 : 0;
    }
    int ans = 0;
    path[i] = 'r';
    ans += f(path, i+1);
    path[i] = 'e';
    ans += f(path, i+1);
    path[i] = 'd';
    ans += f(path, i+1);
    return ans;
}

int main(){
    for(int i=1;i<=10;i++){
        vector<char> path(i, '/');
        cout << f(path, 0) << endl;
    }
}