/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        backtrack(nums, s, 0);
        vector<vector<int>> result(s.begin(), s.end());
        
        return result;
    }
    
    void backtrack(vector<int>& nums, set<vector<int>>& s, int index){
        
        if(index == nums.size()){
            
            if(s.find(nums) != s.end())         //(when 2+ number are repeated and 1 unique)
                cout<<'\n'<<s.size();
            
            s.insert(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++){
            
            swap(nums[i], nums[index]);
            backtrack(nums, s, index + 1);
            swap(nums[i], nums[index]);
            
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
    }
};
/*
    There can be duplicate permutation even after skipping the duplicate values
    To prevent above, use set to store the permutations.
*/

// ************************************************ Using Set ************************************************

class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int index){
        
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i = index; i < nums.size(); i++){
            
            if(s.find(nums[i]) != s.end())
                continue;
            
            s.insert(nums[i]);
            swap(nums[i], nums[index]);
            backtrack(nums, res, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};

// do not permute the duplicate at loop level (which means skip the num[index])

