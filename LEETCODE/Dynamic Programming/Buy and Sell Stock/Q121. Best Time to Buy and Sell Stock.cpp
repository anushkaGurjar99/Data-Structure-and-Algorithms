/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() < 2)
            return 0;
        
        int result = 0;
        int sell = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > sell)
                result = max(result, prices[i] - sell);
            
            sell = min(sell, prices[i]);
        }
        
        return result;
    }
};

/*
Idea is to Buy the stock on minimum Bar and sell on maximum Bar.
Initially we buy stock on 0th day.

  check all days from 1..n
    If a Day has higher Bar then i (update result)
    Update minimum bar (is valid)
*/
