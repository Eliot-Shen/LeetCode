#include <bits/stdc++.h>
#include <iostream>

class Unionset{
    public:
        void build(int num);
        int find(int i);
        bool issameset(int x, int y);
        void unionset(int x, int y);
        int largest_size();
        int num_father();

    private:
        int n;
        const int MAXN = 100001;
        std::vector<int> father;
        std::vector<int> size;
        std::vector<int> stack;
};
void Unionset::build(int num){
    n = num;
    father.resize(MAXN);
    size.resize(MAXN);
    stack.resize(MAXN);//必须要，不然会报错
    for(int i=1;i<=num;i++){
        father[i] = i;
        size[i] = 1;
    }
}
int Unionset::find(int i){
    int ssize = 0;
    while(i != father[i]){
        stack[ssize++] = i;
        i = father[i];
    }
    while(ssize > 0){
        father[stack[--ssize]] = i;
    }
    return i;
}
bool Unionset::issameset(int x, int y){
    return find(x) == find(y);
}
void Unionset::unionset(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy){
        if(size[fx] >= size[fy]){
            size[fx] += size[fy];
            father[fy] = fx;
        }else{
            size[fy] += size[fx];
            father[fx] = fy;
        }
    }
}
int Unionset::largest_size(){
    auto maxit = std::max_element(size.begin()+1,size.end());
    return *maxit;
}
int Unionset::num_father(){
    std::set<int> num_class;
    for(int i=1;i<=n;i++){
        num_class.insert(find(i));
    }
    return num_class.size();
}

int main(){
    int n,m;
    std::cin>>n>>m;
    Unionset classes;
    classes.build(n);
    for(int i=0;i<m;i++){
        int a,b;
        std::cin>>a>>b;
        classes.unionset(a,b);
    }
    std::cout << classes.num_father() << " ";
    std::cout << classes.largest_size();
}