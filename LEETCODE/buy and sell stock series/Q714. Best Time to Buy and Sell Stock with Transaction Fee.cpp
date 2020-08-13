/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution{
public:
    int maxProfit(vector<int>& prices, int fee){
        
        if(prices.size() < 1)
            return 0;
        
        int noStock = 0;
        int oneStock = -prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            noStock = max(noStock, oneStock + prices[i] - fee);
            oneStock = max(oneStock, noStock - prices[i]);
        }
        
        return noStock;
    }
};

// https://www.youtube.com/watch?v=Y-iqcYqlWwA
