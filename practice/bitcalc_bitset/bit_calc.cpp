#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BitCalc{
public:
    int add(int a, int b){
        int ans = a;
        while(b != 0){
            ans = a ^ b;
            b = (a & b) << 1;
            a = ans;
        }
        return ans;
    }
    int minus(int a, int b){
        return add(a, neg(b));
    }
    int neg(int n){
        return add(~n, 1); 
    }
    int multiply(int a, int b){
        int ans = 0;
        while(b!=0){
            if(b&1){
                ans = add(ans, a);
            }
            a <<= 1;
            b >>= 1;
        }
        return ans;
    }
    int round_division(int a, int b){
        int x = a < 0 ? neg(a): a;
        int y = b < 0 ? neg(b): b;
        int ans = 0;
        for(int i=30; i>=0; i = minus(i, 1)){
            if((x>>i) >= y){
                ans |= (1<<i);
                x = minus(x, y<<i);
            }
        }
        return a < 0 ^ b < 0 ? neg(ans) : ans;
    }
    int divide(int a, int b) {
        if(a == INT_MIN && b == INT_MIN){
            return 1;
        }
        if(a!=INT_MIN&&b!=INT_MIN){
            return round_division(a,b);
        }
        if(b==INT_MIN){
            return 0;
        }
        if(b == neg(1)){
            return INT_MAX; // 题目规定
        }
        a = add(a, b > 0 ? b : neg(b)); 
        //a是最小，转不成绝对值INT_MAX，b不是最小，也不是-1,a=a+|b|,让a可以转换为绝对值
        int ans = round_division(a,b);
        int offset = b > 0 ? neg(1) : 1;
        return add(ans, offset); //div(a+b,b)-1
    }
};
int main(){
    BitCalc calculator;
    cout << calculator.multiply(-4, 5) << endl;
    cout << calculator.round_division(7,-3);
}