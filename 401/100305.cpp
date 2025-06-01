#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int valueAfterKSeconds(int n, int k) {
    int a[n];
    fill(a,a+n,1);
    for(int i=1;i<=k;i++){
        int b[n];
        copy(a,a+n,b);
        int s = a[0];
        for(int j=1;j<n;j++){
            a[j]=b[j]+s;
            s = a[j]%100000007;
        }
        // for(int p=0;p<n;p++){
        //     cout << a[p] << " ";
        // }
        // cout << endl;
    }
    return a[n-1]%100000007;
}
int main(){
    int n,k;
    cin >> n >> k;
    cout << valueAfterKSeconds(n,k);
}