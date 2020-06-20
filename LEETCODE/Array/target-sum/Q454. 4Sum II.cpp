/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        
        unordered_map<int, int> m1 = getSumOfPairs(A, B);
        
        int result = 0;
        for(auto k: C){
            for(auto l: D){
                int target = 0 - k - l;  
                if(m1[target] > 0)
                    result += m1[target];               // get number of combination
            }
        }
        
        return result;
    }
    
    unordered_map<int, int> getSumOfPairs(vector<int>& A, vector<int>& B){
        unordered_map<int, int> m;
        
        for(auto i: A){
            for(auto j: B)
                m[i + j]++;
        }
        
        return m;
    }
    
};

/*
Space Complexity: 2N
Time Complexity: N^2

Get sum-frequency of each element of A and B (map)
check combination sum 0 of map + C[k] + D[l]
*/

