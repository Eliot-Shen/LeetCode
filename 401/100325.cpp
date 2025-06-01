class Solution {
public:
    int numberOfChild(int n, int k) {
        int i=0;
        int pos = 0;
        bool flag = true;
        while(i!=k){
            if(pos==n-1){
                flag = false;
            }
            if(pos==0) flag = true;
            if(flag) pos++;
            else pos--;
            i++;
        }
        return pos;
    }
};