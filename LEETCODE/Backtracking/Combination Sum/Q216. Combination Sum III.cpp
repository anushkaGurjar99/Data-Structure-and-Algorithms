/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n){
        
        vector<vector<int>> res;
        backtrack(res, {}, k, n, 1);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int> c, int limit, int target, int num){
        if(target == 0 && limit == 0){
            res.push_back(c);
            return;
        }
        
        for(int i = num; i <= min(target, 9); i++){
            c.push_back(i);
            if(target - i >= 0 && limit > 0)
                backtrack(res, c, limit - 1, target - i, i + 1);
            else
                break;
            c.pop_back();
        }
    }
};

/*
    limit shows how many max elements can be used to obtain the target.
    we can use 1 to 9 numbers (no duplicates)
    
    at each combination we check
        is combination sum equals to 'Target'
        does it contain exact 'limit' numbers
*/


