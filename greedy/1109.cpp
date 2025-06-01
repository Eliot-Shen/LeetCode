#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            vector<int> flights(n);
            fill(flights.begin(),flights.end(),0);
            for(vector<int> book: bookings){
                int start=book[0]-1;
                int end=book[1];
                flights[start] += book[2];
                if(end < n){
                    flights[end] -= book[2];
                }   
            }
            for(int j=1;j<n;j++){
                flights[j] += flights[j-1];
            }
            return flights;
        }
    };