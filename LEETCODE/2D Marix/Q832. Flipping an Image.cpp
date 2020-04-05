/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A){
        
        for(int row = 0; row < A.size(); row++){
            
            int start = 0;
            int end = A[row].size() - 1;
            while(start <= end){
                
                int swap = 1 ^ A[row][start];
                A[row][start] = 1 ^ A[row][end];
                A[row][end] = swap;
        
                start++;
                end--;
            }
        }
        
        return A;
    }
};


// XOR with 1 works same as negation
