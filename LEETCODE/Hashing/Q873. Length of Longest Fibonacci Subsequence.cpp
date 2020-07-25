/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

int lenLongestFibSubseq(int* A, int ASize){

        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        
        for(int i = 0; i < A.size(); i++){
            
            for(int j = i + 1; j < A.size(); j++){
                
                int a = A[i];
                int b = A[j];
                int len = 2;
                
                while(s.count(a + b)){
                    int c = a + b;
                    a = b;
                    b = c;
                    len++;
                }
                
                res = max(res, len);
            }
        }
        
        return res > 2 ? res : 0;    
}

/*
Start from base (A[i], A[j]) as the first two element in the sequence,
we try to find the Fibonacci like subsequence as long as possible,

Initial (a, b) = (A[i], A[j])
While the set s contains a + b, we update (a, b) = (b, a + b).
In the end we update the longest length we find.
*/
