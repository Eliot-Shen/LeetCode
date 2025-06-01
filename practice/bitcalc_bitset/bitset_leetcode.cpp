#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Bitset {
private:
    vector<int> bitset;
    int size;
    int ones;
    int zeros;
    bool reverse; // set reverse variable to prevent from traverse the whole bitset
public:
    Bitset(int n) {
        bitset.resize((n+31)/32);
        size = n;
        zeros = n;
        ones = 0;
        reverse = false;
    }
    
    void fix(int idx) {
        int index = idx/32;
        int bit = idx%32;
        if(!reverse){
            if((bitset[index] & (1<<bit)) == 0){
                zeros--;
                ones++;
                bitset[index] |= (1<<bit);
            }
        }else{
            if((bitset[index] & (1<<bit)) != 0){
                zeros--;
                ones++;
                bitset[index] ^= (1<<bit);
            }
        }
    }
    
    void unfix(int idx) {
        int index = idx/32;
        int bit = idx%32;
        if(!reverse){
            if((bitset[index] & (1<<bit)) != 0){
                zeros++;
                ones--;
                bitset[index] ^= (1<<bit);
            }
        }else{
            if((bitset[index] & (1<<bit)) == 0){
                zeros++;
                ones--;
                bitset[index] |= (1<<bit);
            }
        }
    }
    
    void flip() {
        reverse = !reverse;
        swap(ones, zeros);
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string out = "";
        for(int k=0,i=0;i<size;k++){
            int num = bitset[k];
            for(int j=0; j<32 && i<size; j++,i++){
                int status = (num >> j) & 1;
                status ^= reverse ? 1 : 0;
                out += status ? "1" : "0";
            }
        }
        return out;
    }

};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */