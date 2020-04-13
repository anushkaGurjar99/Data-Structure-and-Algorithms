/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/amazing-subarrays/

int Solution::solve(string A){
    
    int count = 0;
    const char* vowel = "aeiouAEIOU";
    
    for(int i = 0; i < A.size(); i++){
        if(strchr(vowel, A[i]) != nullptr)
            count += A.length() - i;
    }
    
    return count % 10003;
}
