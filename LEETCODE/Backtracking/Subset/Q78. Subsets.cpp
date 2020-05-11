/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/subsets/

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res;
        backtrack(nums, res, {}, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> curr, int index){
        
        res.push_back(curr);
        if(index == nums.size())
            return;
          
        for(int i = index; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, res, curr, i + 1);
            curr.pop_back();
        }      
    }
};

/*
    approach: same as generating binary table for n element.
    time complexity: N * 2^N since each element could be absent or present.
                    (N for copy them into output array)
                    
    array = [1, 2, 3]
    
    Empty                   0 0 0
    1                       0 0 1
    1 2                     0 1 1
    1 2 3                   1 1 1
    1 3                     1 0 1
    2                       0 1 0
    2 3                     1 1 0
    3                       1 0 0

Time complexity: total is call stack of n + output of n2^n = O(n2^n). 
If we don't include the output (eg if just asked to print in an interview) then just O(n) of course.
*/

// ***************************************************** Iterative *****************************************************

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        
        vector<vector<int>> result;
        vector<bool> table(nums.size(), true);
        int limit = pow(2, nums.size());
        
        while(limit--){
            nextBinaryCombination(table);
            vector<int> active;
            for(int i = 0; i < nums.size(); i++){
                if(table[i])
                    active.push_back(nums[i]);
            }
    
            result.push_back(active);
        }
        
        return result;
    }
    
    void nextBinaryCombination(vector<bool>& table){
        for(int i = table.size() - 1; i >= 0; i--){
            if(table[i]){
                table[i] = false;
            }
            else{
                table[i] = true;
                break;
            }
        }
    }
};


/*
Lexicographic generation based on the mapping between binary bitmasks and input set.
(same as binary table)
*/
