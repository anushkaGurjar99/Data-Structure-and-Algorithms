/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		
        unordered_map<int, int> m;
		
        for (int x : nums) 	
            m[x]++;
                
		priority_queue<P, vector<P>, greater<P>> q;      
        // this is syntax of MIN Heap, by default it is the MAX heap
        
	    for(auto x : m){
		    if (q.size() < k){
                q.push({x.second, x.first});
            }
			else{
				if(q.top().first < x.second){
					q.pop();
					q.push({x.second, x.first});
				}
			}
		}
		
        vector<int> result;
		while (!q.empty()){
			result.push_back(q.top().second);
			q.pop();
		}
        
		return result;
	}
};
