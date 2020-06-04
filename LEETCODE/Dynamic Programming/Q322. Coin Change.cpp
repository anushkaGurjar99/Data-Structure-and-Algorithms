/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/coin-change/

class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        
        int MAX = amount + 1;
        vector<int> cache(amount + 1, MAX);
        
        cache[0] = 0;
        for(auto coin : coins){
            for(int i = coin; i <= amount; i++)
                cache[i] = std::min(cache[i], cache[i - coin] + 1);
        }
        
        return cache[amount] == MAX ? -1 : cache[amount];
    }
};

/* 
Keep updating costs by checking coins combinations 
Visit all coin combinations then proceed with minimum
*/

// ********************************************************** BFS ****************************************************

class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        
        if(amount == 0)
            return 0;
        
        int result = -1;
        unordered_set<int> visited;
        queue<int> q;
        int levelMarker = -1;
        int level = 0;
        
        q.push(0);
        q.push(levelMarker);
        
        while(!q.empty() && result == -1){
            if(q.front() == levelMarker){
                q.pop();
                if(q.empty())
                    break;
                q.push(levelMarker);
                level++;
            }
            
            int top = q.front();
            q.pop();
            
            for(auto itr: coins){
                int next = itr + top;
                if(next == amount){
                    result = level + 1;
                    break;
                }
                
                if(visited.find(next) == visited.end() && next < amount){
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        
        return result;
    }
};

/*
BFS
At each Level we will add all valid coins in Top of Q (top + coin[i]) and push the next value in Q.
    - valid coins means unvisited amount
    - keep a levelMarker for tracking
    
    example: 
        coins - [1, 3, 5]           target = 11
        
                          0
                    /     |     \
                    1     3     5                       Level 1
                 / | \  / | \  / | \        
                2  4  6     8    7  10                  Level 2
                   \  \     
                   9  11                                Level 3 (target found)
*/
