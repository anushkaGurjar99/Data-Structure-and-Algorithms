/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        
        if(nums.size() < 3)
            return INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        int minimum = INT_MAX;
        int result = INT_MAX;
        
        for(int i = nums.size() - 1; i > 0; i--){
            int start = 0;
            int end = i - 1;
            
            while(start < end){
                int currDifference = (nums[i] + nums[start] + nums[end]) - target;
                
                if(currDiff < result){
                    result = currDifference;
                }
                
                (currSum > target) ? --end : ++start;
            }
        }
        
        return result;
    }
};


// another approach: same as 3Sum, using hashmap
