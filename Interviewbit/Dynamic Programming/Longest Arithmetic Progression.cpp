/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A){
    
    if(A.size() <= 2)
        return A.size();
    
    int n = A.size();
    int result = 0;
    vector<unordered_map<int, int>> dp(n);
        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int diff = A[i] - A[j];
            
            dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
            
            result = max(result, dp[i][diff]);
        }
    }
    return result;
}

/*
How to keep track of the length as well as the difference? 
We can use a hashmap, whose key is the difference and value is the length. 

The optimization: 
    for two elements A[i] and A[j] where j < i, A[i] - A[j] is a critical condition. 
    
    If the hashmap has key 'diff', 
        There exist an subsequence ending at index j, with difference diff and length dp[j][diff]. 
    And we just add the length by 1. 
    
    If hashmap does not have the key diff, 
        then those two elements can form a 2-length arithmetic subsequence.
*/


// ******************************************************* Using Set *******************************************************

int Solution::solve(const vector<int> &A){
    
    if(A.size() <= 2)
        return A.size();
    
    unordered_multiset<int> um;
    unordered_set<int> us;
    int result = 0;
    
    for(int i = 0; i < A.size() - 1; i++){
        int iDiff = A[i] - A[i + 1];
        int jump = i;

        for(int j = i + 1; j < A.size(); j++){
            int currDiff = A[i] - A[j];
            
            if(currDiff == iDiff && jump + 1 == j)
                jump++;
                
            um.insert(currDiff);
            us.insert(currDiff);
        }
        
        i = jump - 1;
    }
    
    for(auto freq: us)
        result = result < um.count(freq) + 1 ? um.count(freq) + 1: result;
        
    return result;
}

/*
    [9, 4, 7, 2, 10]
    
        9   4   7   2   10
    9   .  -5  -2  -7   1
    4   .   .   3  -2   6
    7   .   .   .  -5   3
    2   .   .   .   .   8
    10  .   .   .   .   .
    
Count difference frequencies and return the MAXIMUM + 1.  (+1 is for self)
    
To be noted: 
    Skip contigous similar difference Subarray elements (starting from i) in next iteration.
    [1, 1, 1, 1]
    
        1   1   1   1
    1   .   1   1   1
    1   .   .   .   .   
    1   .   .   .   .
    1   .   .   .   .    
*/

