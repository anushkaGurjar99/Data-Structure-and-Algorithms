/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        if(prices.size() <= 1)
            return 0;
        
        int size = prices.size();
        vector<int> dp(size, 0); 
        
        for(int i = 0; i < size / 2; i++){
            
            vector<int> next(size, 0);
            for(int j = 1; j < size; j++){
                
                for(int k = 0; k < j; k++){
                    int possibility = (k > 1) ? dp[k - 2] : 0;
                    next[j] = max(next[j], prices[j] - prices[k] + possibility);
                }
                
                next[j] = max(next[j], next[j - 1]);
            }
            
            dp = next;
        }
        
        return dp[size - 1];
    }
};

// TLE for 2 cases.
