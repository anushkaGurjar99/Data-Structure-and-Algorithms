/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K){
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    for(int i = K; i < arrive.size(); i++){
        if(arrive[i] < depart[i - K])
            return false;
    }
    return true;
}

// *********************************************************************************************************************************************************************

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K){
    
    if(K >= arrive.size())
        return 1;
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    for(int i = 0; i < arrive.size() - K; i++){
        if(arrive[i + K] < depart[i])
            return false;
    }
    
    return true;
}
/*
        1   2   3   4   5
        2   2   2   2   2

Check how many overlaps are present in one particular range
If the number of overlaps are greater than the number of rooms, 
we can say that we have less rooms to accommodate guests.
*/

