/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/noble-integer/

int Solution::solve(vector<int> &A){
    
    sort(A.begin(), A.end());
    int size = A.size() - 1;
    
    for(int i = 0; i < size; i++){
        if(A[i] == A[i + 1])
            continue;
            
        if(size - i == A[i])
            return 1;
    }
    
    return A[size] == 0 ? 1 : -1;
}

/*
    Sort the array
    Check if there exist SIZE - CURRENT POS elements or not.
    
    At last check the edge case which is A[SIZE] == 0.
*/

