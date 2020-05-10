/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/combinations/

class Solution{
public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res;
        backtrack(res, {}, n, k, 1);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int> c, int end, int limit, int curr){      
        
        if(limit < 0)
            return;
        
        if(limit == 0){
            res.push_back(c);
            return;
        }
        
        for(int i = curr; i <= end; i++){
            c.push_back(i);
            backtrack(res, c, end, limit - 1, i + 1);
            c.pop_back();
        }
    }    
};

/*
    Do not repeat any element (Start from 1 and goes to "end")
    Form all the combinations
    Store the subset when vector size reaches to "limit"
*/
