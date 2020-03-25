/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        
        if(nums.size() < 4)
            return {};
        
        sort(nums.begin(), nums.end());
        
        return getFourSum(nums, target);
    }
    
    vector<vector<int>> getFourSum(vector<int> nums, int target){
        
        vector<vector<int>> result;
        
        for(int i = 0; i < nums.size() - 3; i++){ 
            for(int j = i+1; j < nums.size() - 2; j++){
                
                int start = j + 1;
                int end = nums.size() - 1;
                
                while(start < end){
                    
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while(nums[start] == nums[start + 1] && start < end - 1)
                            start++;
                        while(nums[end] == nums[end - 1] && end > start + 1)
                            end--;
                        start++;
                        end--;
                    }
                    else{
                        (sum < target) ? ++start : --end;
                    }
                }
                
                while(j < nums.size() - 2 && nums[j] == nums[j+1])
                    j++;
            }
            while(i < nums.size() - 3 && nums[i] == nums[i+1])
                i++;
        }
        
        return result;
    }
};
