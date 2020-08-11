/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        int result = 0;
        if(prices.size() < 1)
            return result;
            
        int minP = prices[0];
        int maxP = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            if(minP > prices[i])
                minP = maxP = prices[i];
            
            if(maxP < prices[i])
                maxP = prices[i];
            
            result = max(result, maxP - minP);
        }
        
        return result;
    }
};

/*
    A1: brute force, check all combinations
    A2: two-pointers
        keep updating both pointers MIN and MAX.
        calculate result in each iteration.
*/
