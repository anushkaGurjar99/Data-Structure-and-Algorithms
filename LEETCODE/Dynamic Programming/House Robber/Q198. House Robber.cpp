/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/house-robber/

class Solution{
public:
    int rob(vector<int>& nums){
        
        if(nums.size() < 1)
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        
        return dp[nums.size() - 1];
    }
};

/*
A robber has 2 options:     
    a) rob current house i; 
    b) don't rob current house.
If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one
before previous i-2 and gets all cumulative loot that follows.

If an option "b" is selected the robber gets all the possible loot from robbery of i-1.

Each cell stores the max profit till that position.
*/
