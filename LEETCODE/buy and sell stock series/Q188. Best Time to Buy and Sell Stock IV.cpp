/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution{
public:
    int maxProfit(int K, vector<int>& prices){
        
        if(K == 0 || prices.size() <= 1)
            return 0;
        
        int size = prices.size();
        
        if(K >= size / 2 )
            return edgeCase(prices);
        
        vector<int> dp(size, 0);
        
        for(int i = 0; i < K; i++){
            vector<int> next(size, 0);
            
            for(int j = 1; j < size; j++){
                
                for(int k = 0; k < j; k++){
                    int d = (k > 0) ? dp[k - 1] : 0;
                    next[j] = max(next[j], prices[j] - prices[k] + d);
                }
                
                next[j] = max(next[j], next[j - 1]);
            }
            
            dp = next;
        }
        
        return dp[size - 1];
    }
    
    int edgeCase(vector<int>& prices){
        int result = 0;
        
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i] < prices[i + 1])
                result += prices[i + 1] - prices[i];
        }
        
        return result;
    }
};

// memory optimization.
// https://www.youtube.com/watch?v=oDhu5uGq_ic

// edgeCase: if all transactions are possible, Do all.

