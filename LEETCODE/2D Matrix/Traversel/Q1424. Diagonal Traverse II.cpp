/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/diagonal-traverse-ii/

class Solution{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums){
        
        int size = nums.size();
		vector<int> result;

        queue<pair<int, int>> q;
        q.push({0,0}); 
		
		// BFS
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            result.push_back(nums[p.first][p.second]);
			
            if(p.second == 0 && p.first + 1 < size) 
                q.push({p.first + 1, p.second});
			
            if(p.second + 1 < nums[p.first].size())
                q.push({p.first, p.second + 1});
        }
        
        return result;
    }
};

/*
In the queue for BFS, insert the index for first cell of first row, i.e. {0,0}

For each iteration, 
    for the front in Q push the index for cell just below it (if the current cell is the first in its row.)
    Then push the index for right neighbour cell (if exists)
*/

