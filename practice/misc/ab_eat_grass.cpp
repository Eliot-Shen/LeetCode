#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string compete(int rest, string cur){
    // Return the winner.
    string enemy = (cur == "A") ? "B" : "A";
    if(rest < 5){ // initial condition
        return (rest == 0 || rest == 2) ? enemy : cur;
    }
    int pick = 1;
    while(pick <= rest){
        if(compete(rest - pick, enemy) == cur){
            return cur;
        }
        pick *= 4;
    }
    return enemy;
}

int main(){
    string first = "A";
    for(int i=0;i<=20;i++){
        cout << i << ":" <<compete(i, first) << endl;
    }
}