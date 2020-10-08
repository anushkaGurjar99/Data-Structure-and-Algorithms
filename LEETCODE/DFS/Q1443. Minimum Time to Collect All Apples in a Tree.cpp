/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution{
        unordered_map<int, vector<int>> m;
        unordered_map<int, bool> v;
        
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        for(auto itr: edges){
            m[itr[0]].push_back(itr[1]);
            m[itr[1]].push_back(itr[0]);
        }
        return helper(hasApple, 0, 0);    
    }
    
    int helper(vector<bool>& hasApple, int myCost, int node){
        if(v[node] == 1)
            return 0;        
        
        v[node] = 1;
        
        int childrenCost = 0;
        for(auto itr: m[node])
            childrenCost += helper(hasApple, 2, itr);
        
        if(childrenCost == 0 && !hasApple[node])
            return 0;
            
        return childrenCost + myCost;
    }
};

/*
1. Construct the graph first to have a better representation of the structure.
2. For each node, check if any of its children have apples and 
   find the total cost in terms of time in seconds of collecting those.
3. If there is at least one child with an apple, then we have to collect it. 
   So we will also have to add the cost (time required) of reaching that node.
4. return the total time.
*/


