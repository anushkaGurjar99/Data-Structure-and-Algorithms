/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Dijkstra's algorithm (Each time we are exploring MIN cost path)

typedef vector<pair<int,int>> VP;
typedef tuple<int,int,int> ti;

class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){
        
        vector<VP> vp(n);
        
        for(auto f: flights)   
            vp[f[0]].emplace_back(f[1], f[2]);
        
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        
        pq.emplace(0, src, K+1);
        
        while(!pq.empty()){
            
            auto [cost,u,stops] = pq.top();
            pq.pop();
            if(u == dst)  
                return cost;
            if(!stops)  
                continue;
            
            for(auto to: vp[u]){
                auto [v,w] = to;
                pq.emplace(cost+w, v, stops-1);
                //cout<<"\n"<<cost + w<<" "<<v<<" "<<stops-1;
            }
        }
        return -1;
    }
};

/*
PQ elements -
    top[0] = current total price
    top[1] = current source city
    top[2] = max distance to destination allowed

initliazation :
    add original source city to pq with price = 0 & distance allowed = k + 1

pq compares each object by total price so far

Then explore:
    get PQ top which is minimum
    
    if we are out of stops then continue (stop exploring curr and move to next PQ element)
    
    if top.source is equal to destination 
        return the cost (since it is minimum, no -ve edge)
    else 
        get curr total price, curr source city & distance (stops - 1) 
*/
