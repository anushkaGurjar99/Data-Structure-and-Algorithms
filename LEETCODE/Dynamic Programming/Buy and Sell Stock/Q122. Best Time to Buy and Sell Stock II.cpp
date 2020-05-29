/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - prices[i-1] > 0)
                profit += prices[i] - prices[i-1];
        }
        
        return profit;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/39474/Why-the-greedy-algorithm-works-(pairwise-differences-only)

/*
Greedy algorithm - 
    buy as soon as profitable Bar found.    (profitable bar means selling price > buying price)
*/
