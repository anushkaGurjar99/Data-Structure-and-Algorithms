/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        backtrack(candidates, res, {}, target, 0);          // input array, result, set of target sum elements, target, start index
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> c, int target, int index){
        if(target == 0){
            res.push_back(c);
            return;
        }    
        
        for(int i = index; i < nums.size(); i++){
            
            c.push_back(nums[i]);
            if(target - nums[i] >= 0)
                backtrack(nums, res, c, target - nums[i], i + 1);
            else
                break;
            c.pop_back();
            
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])                // skip duplicates
                i++;
        }
    }
};

/*
    Constraints:
        1. No elements can be used multiple times
        2. No duplicate combinations allowed

    Solution:
        Once an element is used, skip all duplicates of it
        While forming combination, Do not use same element more than one times
    
    Rest is same as Combination sum
*/
