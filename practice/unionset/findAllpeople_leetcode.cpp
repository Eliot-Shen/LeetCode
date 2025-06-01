#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://leetcode.cn/problems/find-all-people-with-secret/solutions/1126597/bing-cha-ji-pai-xu-javashuang-bai-xiang-5gbrx/
class Solution {
    vector<int> p;
    map<int, vector<pair<int, int>>> tm;//t时刻所有的会议。
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        p.resize(n);
        for(int i = 0; i < n; ++i) p[i] = i;
        p[firstPerson] = 0;
        for(auto &m : meetings) tm[m[2]].push_back({m[0], m[1]});

        for(auto &[t, m] : tm){
            for(auto &[z1, z2] : m){
                int x = find(z1), y = find(z2);
                if(!x || !y ) p[x] = 0, p[y] = 0;
                p[y] = p[x];
            }
            for(auto &[z1, z2] : m){
                int x = find(z1), y = find(z2);
                if(!x || !y ) p[x] = 0, p[y] = 0;
                else p[z1] = z1, p[z2] = z2;
            }                     
        }

        vector<int> ans = {0};
        for(int i = 1; i < n; ++i) if(!find(i)) ans.emplace_back(i);
        return ans;
    }
};

// class Solution {
// private:
//     const int MAXN = 100001;
//     std::vector<int> father;
//     std::vector<bool> secret; // label info
// public:
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         build(n, firstPerson);
//         sort(meetings.begin(), meetings.end(), cmp);
//         int m = meetings.size();
//         for(int l=0, r; l<m; ){
//             r=l;
//             while(r+1 < m && meetings[l][2]==meetings[r+1][2]){
//                 r++;
//             }
//             for(int i=l;i<=r;i++){
//                 unionset(meetings[l][0], meetings[l][1]);
//             }
//             for(int i=l,a,b; i<=r; i++){
//                 a = meetings[i][0];
//                 b = meetings[i][1];
//                 if(!secret[find(a)]){
//                     father[a] = a;
//                 }
//                 if(!secret[find(b)]){
//                     father[b] = b;
//                 }
//             }
//             l = r+1;
//         }
//         std::vector<int> ans;
//         for(int i=0; i<n; i++){
//             if(secret[find(i)]){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
//     static bool cmp(vector<int> a, vector<int> b){
//         return a[2] <= b[2];
//     }
//     void build(int n, int first){
//         father.resize(MAXN);
//         secret.resize(MAXN);
//         for(int i=0;i<n;i++){
//             father[i] = i;
//             secret[i] = false;
//         }
//         father[first] = 0;
//         secret[0] = true;
//     }
//     int find(int i){
//         if(i != father[i]){
//             i = find(father[i]);
//         }
//         return father[i];
//     }
//     bool issameset(int x, int y){
//         return find(x) == find(y);
//     }
//     void unionset(int a, int b){
//         int fx = find(a);
//         int fy = find(b);
//         if(fx!=fy){
//             father[fx] = fy;
//             if(secret[fx]) secret[fy] = true;
//         }
//     }
// };