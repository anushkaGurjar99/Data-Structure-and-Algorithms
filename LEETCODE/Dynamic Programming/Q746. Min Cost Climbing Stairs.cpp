/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution{
public:
    int minCostClimbingStairs(vector<int>& cost){
        if(cost.size() == 0)
            return 0;
        
        if(cost.size() == 1)
            return cost[0];
        
        int first = cost[0];
        int second = cost[1];
        
        for(int i = 2; i < cost.size(); i++){
            int curr = cost[i] + min(first, second);
            //cout<<" - "<<curr;
            
            first = second;
            second = curr;
        }
        
        return min(first, second);
    }
};
