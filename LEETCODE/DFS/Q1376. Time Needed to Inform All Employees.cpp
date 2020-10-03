/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution{
public:
    unordered_map<int, vector<int>> m;    // parent: child_1...child_n
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        for(int i = 0; i < n; i++)
            m[manager[i]].push_back(i);
        
        return dfs(informTime, headID);
    }
    
    int dfs(vector<int>& informTime, int currNode){
        int time = 0;
        
        for(auto itr : m[currNode])
            time = max(time, dfs(informTime, itr));
        
        return informTime[currNode] + time;			
    }
};

/*
Approach: DFS
    store parent-child relationship in a MAP
    traverse all the paths (from head) with given weights
    return the maximum sum from root to leaf
*/
