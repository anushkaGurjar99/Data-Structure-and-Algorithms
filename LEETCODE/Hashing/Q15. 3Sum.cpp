/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/3sum    

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        
        if(nums.size() < 3)
            return {};
        
        unordered_multimap<int, int> m;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
            m.insert({nums[i], i});
        
        return getThreeSum(nums, m);
    }
    
    vector<vector<int>> getThreeSum(vector<int> nums, unordered_multimap<int,int> m){
        vector<vector<int>> result;
        
        // for both for loop, check only relevant elements
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            for(int j = i+1; j < nums.size() && (nums[i] + nums[j]) <= 0; j++){     
                
                auto itr = m.find(-(nums[i] + nums[j]));
                
                if(itr != m.end() && itr->second > j)
                    result.push_back({nums[i], nums[j], itr->first});
                
                while(j < nums.size() - 1 && nums[j] == nums[j+1])    // remove duplicates
                    j++;
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1])        // remove duplicates
                i++;
        }
        
        return result;
    }
};
