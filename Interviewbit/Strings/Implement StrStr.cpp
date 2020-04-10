/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/implement-strstr/

int Solution::strStr(const string A, const string B) {
    
    if(A == "" || B.length() > A.length() || B == "")
        return -1;
        
    int pos = -1;
    
        
    // check each substring of size needle in a sequence
    for(int i = 0; i < A.length(); i++){

        int save = i;
        int j;
        for(j = 0; j < B.length(); j++, i++){
            if(B[j] != A[i])
                break;
        }
        i = save;
            
        if(j == B.length()){
            pos = save;
            break;
        }
    }
    
    return pos;
}
