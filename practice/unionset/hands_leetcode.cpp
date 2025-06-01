#include <bits/stdc++.h>
#include <iostream>

class Unionset{
    public:
        void build(int num);
        int find(int i);
        bool issameset(int x, int y);
        void unionset(int x, int y);
        int minSwapsCouples(std::vector<int>& row);

    private:
        const int MAXN = 32;
        std::vector<int> father;
        int sets;
};
int Unionset::minSwapsCouples(std::vector<int>& row){
    int n = row.size();
    build(n/2);
    for(int i=0;i<n;i+=2){
        unionset(row[i]/2,row[i+1]/2);
    }
    return n / 2 - sets;
}
void Unionset::build(int m){
    father.resize(MAXN);
    for(int i=0;i<m;i++){
        father[i] = i;
    }
    sets = m;
}
int Unionset::find(int i){
    if(i != father[i]){
        i = find(father[i]);
    }
    return father[i];
}
bool Unionset::issameset(int x, int y){
    return find(x) == find(y);
}
void Unionset::unionset(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy){
        father[fx] = fy;
        sets--;
    }
}