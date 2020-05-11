/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/permutations/

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int index){
        
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            backtrack(nums, res, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};

/*
    swap marked element with all successor elements (including self) to generate permutations.
    store result when all elements are permuted.
*/
