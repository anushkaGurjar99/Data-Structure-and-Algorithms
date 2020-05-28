/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/possible-bipartition/

class Solution{
public:
    bool possibleBipartition(int N, vector<vector<int>> &edges) {
        vector<vector<int>> adj(N + 1); 
        
        // creating an undirected graph
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(N + 1, 0); 
        vector<bool> explored(N + 1, false); 
        queue<int> q;
        
        for(int i = 1; i <= N; ++i){
            if(color[i] == 0){
                color[i] = 1;
                q.push(i);
                
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    
                    if(explored[u])
                        continue;
                    explored[u] = true;
                    
                    for(auto v: adj[u]){
                        if (color[v] == color[u])
                           return false;
                        color[v] = (color[u] == 1) ? 2 : 1;
                        q.push(v);
                    }
                }
            }
        }      
        return true;
    }
};
