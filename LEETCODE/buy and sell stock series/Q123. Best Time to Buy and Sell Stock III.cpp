/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        int oneBuy = INT_MAX;
        int twoBuy = INT_MAX;

        for(auto p: prices){
            oneBuy        = min(oneBuy, p);
            oneBuyOneSell = max(oneBuyOneSell, p - oneBuy);
            twoBuy        = min(twoBuy, p - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, p - twoBuy);
          }

          return twoBuyTwoSell;
    }
};

/*    
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).

https://www.youtube.com/watch?v=GFa9xlgZcEI
*/


