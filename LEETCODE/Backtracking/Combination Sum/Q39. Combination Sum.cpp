/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, {}, target, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> v, int target, int s){
        
        if(target == 0){
            res.push_back(v);
            return;
        }
        
        for(int i = s; i < nums.size(); i++){
            v.push_back(nums[i]);
            if(target - nums[i] >= 0)
                backtrack(nums, res, v, target - nums[i], i);
            else
                break;
            v.pop_back();
        }
    }
};

/*
    Sort the array (prevent unnecessary calls)    
    
    Explore the current CELL till sum is greater than or equal to Target
        if sum is equal to target
            store vector elements and return from call
        else 
            return from the call as their exist no more combinations
            
    note: when making a new call, start from current index not from begin
*/

