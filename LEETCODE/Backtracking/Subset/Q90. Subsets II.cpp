/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backtrack(nums, result, {}, 0);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> curr, int index){
        res.push_back(curr);
        if(index == nums.size())
            return;
        
        for(int i = index; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, res, curr, i + 1);
            curr.pop_back();
            
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
    }
};

/*
    Sort the array
    Discard duplicates of an element while Backtracking 
    
    for ex: [2, 1, 2, 2]
    
    sorting -> [1, 2, 2, 2]
    
    {}
    1
    1, 2
    1, 2, 2
    1, 2, 2, 2
    
    2
    2, 2
    2, 2, 2
    
    after processing 2 ignore all its duplicates.
*/
