/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& A, int K){
        int zeroCount = 0;
        int start = 0;
        int maxLen = 0;
        
        for( int i = 0; i < A.size(); i++ ){
            
            if(A[i] == 0) 
                zeroCount++;
            
            while(zeroCount > K){
                if(A[start] == 0) 
                    zeroCount--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};


    /*
        Approach:
        1. The question translates to finding the max length of subArray with at most K 0s.
        2. Use sliding window technique. (Two pointer here)
        3. Keep count of the number of 0s found in the current window.
        4. If the count is > K, then increment l until the count goes to <=K.
        5. At each iteration find the maxLen.
        6. Time complexity: O( N ).
    */
    
    
