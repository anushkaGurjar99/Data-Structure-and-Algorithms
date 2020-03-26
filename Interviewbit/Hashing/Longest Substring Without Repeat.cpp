/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A){
    
    unordered_map<char, int> m;
    
    int result = 0;
    int start = 0;
    int end = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        auto itr = m.find(A[i]);
        if(itr != m.end() && itr->second >= start)
            start = itr->second + 1;
            
        result = max(result, i - start + 1);
        m[A[i]] = i;
    }
    
    return result;
}

/*

(memory efficient: storing only recent occurance)

START and i denoting the begin and end of our current window

keep incr i in every iteration, check if s[i] already exist in CURRENT window (IF YES then move START to
that occurance)
*/
