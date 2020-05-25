/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/online-stock-span/

class StockSpanner{
private:
    stack<int> order;
    vector<int> prices;
    int count = 0;
public:
    StockSpanner(){}
    
    int next(int currPrice){
        if(!order.empty()){
            while(!order.empty() && prices[order.top()] <= currPrice)
                order.pop();
        }
        
        int result = order.empty() ? 0 : order.top() + 1;       // Get the resultant Consecutive days
        prices.push_back(currPrice);
        order.push(count);
        count++;
        return count - result;                                  // Return the difference
    }
};

/*
Problem similar to "Daily Temperature" <DS: Stack>

stack 'order':  Maintain a weighted stack of decreasing elements
                Notice that, we only care about elements that occur in increasing order
                
vector 'prices': To store all prices

varible count can be replaced with prices.size()
*/

