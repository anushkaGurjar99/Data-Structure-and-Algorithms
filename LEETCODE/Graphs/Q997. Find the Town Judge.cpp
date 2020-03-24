/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(N == 1)
            return 1;
        if(trust.size() < N - 1)
            return -1;
        
        vector<int> degree(N + 1, 0);
        
        for(auto curr: trust){
            degree[curr[0]]--;
            degree[curr[1]]++;
        }
        
        auto result = find(degree.begin(), degree.end(), N - 1);
            
        return (result == degree.end()) ? -1 :  (result - degree.begin());
    }
};
