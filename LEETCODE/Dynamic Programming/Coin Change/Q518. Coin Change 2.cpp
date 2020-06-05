/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/coin-change-2/

class Solution{
public:
    int change(int amount, vector<int>& coins){
        
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(auto coin: coins){
            for(int i = coin; i < dp.size(); i++)
                dp[i] += dp[i - coin];
        }
        
        return dp[amount];
    }
};

/*
There is 1 way to make 0, which is Base case (: Include no coin).

In each iteration
    Pick a coin and calculate ways to generate the coin set using current coin (i - coin)

Return the target set.
*/
