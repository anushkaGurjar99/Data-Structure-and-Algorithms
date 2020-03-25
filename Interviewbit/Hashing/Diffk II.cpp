/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B){
    
    if(A.size() < 2)
        return 0;
    
    unordered_multimap<int, int> m;
    
    for(int i = 0; i < A.size(); i++){
        
        if(m.find(A[i] - B) != m.end() || m.find(A[i] + B) != m.end())      // 2 possible cases
            return 1;
            
        m.insert({A[i], i});

    }
    
    return 0;
}
