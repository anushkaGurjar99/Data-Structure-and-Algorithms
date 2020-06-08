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
    
    unordered_multiset<int> um;
    unordered_set<int> us;
    int result = 0;
    
    for(int i = 0; i < A.size() - 1; i++){
        int diff = A[i] - A[i + 1];
        int save = i;

        for(int j = i + 1; j < A.size(); j++){
            int curr = A[i] - A[j];
            
            if(curr == diff && save + 1 == j)
                save++;
                
            um.insert(curr);
            us.insert(curr);
        }
        
        i = save - 1;
    }
    
    for(auto itr: us)
        result = result < um.count(itr) + 1 ? um.count(itr) + 1: result;
        
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

