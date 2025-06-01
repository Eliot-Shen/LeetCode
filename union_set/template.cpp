#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define SIZE 100
int set[SIZE];

void initial(int s[]){
    for(int i=0;i<SIZE;i++){
        s[i] = i;
    }
}
// int Find(int s[], int x){
//     while(s[x] != x){
//         x = s[x];
//     }
//     return x;
// }
int find(int s[], int x){//路径压缩
    if(s[x]!=x){
        s[x] = find(s,s[x]);
    }
    return s[x];
}
void merge(int s[], int root1, int root2){
    s[root1] = root2;
}
void Union(int s[], int root1, int root2){
    if(root1 == root2){
        return;
    }else{
        s[root1] = root2;
    }
}

int main(){
    
}