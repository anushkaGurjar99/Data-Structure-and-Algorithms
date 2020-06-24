/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/unique-binary-search-trees/

class Solution{
public:
    int numTrees(int n){
        
        vector<int> uniqueBST(n+1, 0);
        uniqueBST[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++)
                uniqueBST[i] += uniqueBST[j - 1] * uniqueBST[i - j];
        }
        
        return uniqueBST[n];
    }
};

/*
Basically multiplying the array from both ends

    For ex. calculating UniqueBST for 4
        we have already manipulted for 0 to 3 numbers
        1   1   2   5
       [0] [1] [2] [3]
       
       [0] * [3] +
       [1] * [2] +
       [2] * [1] +
       [3] * [0]                = 14
*/
