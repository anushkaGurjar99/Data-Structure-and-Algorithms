/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        int result = 0;
            
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i] < prices[i + 1])
                result += prices[i + 1] - prices[i];
        }
        
        return result;
    }
};

/*
Approach 2:
    a   b   c   d
    
    diff from a to d is nothing but: D(a, b) + D(b, c) + D(c, d)
*/

//*****************************************************************************************************************************************************

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        int result = 0;
        int minP = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minP){
                minP = prices[i];
            }
            else{
                while(i + 1 < prices.size() && prices[i] < prices[i + 1])
                    i++;
                
                result += (prices[i] - minP);
                minP = prices[i];
            }
        }
        
        return result;
    }
};

/*
Approach:
    maintain 2 pointers. (MIN and MAX)
    
    as soon as and match found for MAX,
        since we want max profit and price[i] can't be resued.  
        So we found longest contigous incr order from MAX so that MIN can be justified.
        
    update result
*/
