#include <bits/stdc++.h>
#include <iostream>

class Bitset
{
    public:
        Bitset(int n);
        void add(int num);
        void remove(int num);
        void reverse(int num);
        bool contains(int num);
    private:
        std::vector<int> bitset;
};
Bitset::Bitset(int n){
    // handle 0...n-1
    bitset.resize((n+31)/32); // (a+b-1)/b will round up
}
void Bitset::add(int num){
    bitset[num/32] |= (1<<(num%32));
}
void Bitset::remove(int num){
    bitset[num/32] &= ~(1<<(num%32));
}
void Bitset::reverse(int num){
    bitset[num/32] ^= (1<<(num%32));
}
bool Bitset::contains(int num){
    // int mask = 1<<(num%32);
    // mask &= bitset[num/32];
    // return mask;
    return ((bitset[num/32]>>(num%32)) & 1) == 1;
}


int main(){
    int n = 1000;
    Bitset bset(n);
    bset.add(105);
    std::cout << bset.contains(105) << "\n";
    std::cout << bset.contains(100) << "\n";
    bset.remove(105);
    std::cout << bset.contains(105);
}

