/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B){
    
    unordered_map<int, int> m;                             // element, count
    vector<int> result;
    
    for(int i = 0; i < A.size(); i++){
        int curr = A[i];
        m[curr]++;
        if(i >= B - 1){
            result.push_back(m.size());
            int last = A[i - (B - 1)];
            m[last]--;
            if(m[last] == 0)
                m.erase(last);
        }
    }    
    return result;
}
