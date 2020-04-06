/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        
        int n = matrix.size();
        int start = 0;
        int end = n-1;
        
        while(start < end){
            for(int i = 0; i < (end - start); i++){
                
                swap(matrix[start][start + i], matrix[start + i][end]);     
                swap(matrix[start][start + i], matrix[end][end - i]);       
                swap(matrix[start][start + i], matrix[end - i][start]);     
            }
            start++;
            end--;
        }
    }
};

// swap all 4 values in a sequence
// Ex: 1,2,3,4 => 2,3,4,1 (3 adjecent swapping)

