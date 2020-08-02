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
        
        int size = nums.size();
        
        if(size == 0)
            return 0;
        
        if(size <= 2)
            return (size == 1) ? nums[0] : max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for(int i = 2; i < size; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        
        return max(dp[size - 1], dp[size - 2]);
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
