/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        
        if(nums.size() <= 1)
            return nums.size();
                
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int result = 1;
        
        for(int i = 1; i < nums.size(); i++){
            int count = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    count = max(count, dp[j]);
            }
            dp[i] = count + 1;
            result = max(dp[i], result);
            //cout<<" - "<<dp[i];
        }
        
        return result;
    }
};

/*
Each dp[i] represents longest possible subsequence including ith element.

So for each dp[i]th element we check all its prev elements -
  if no element is smaller than that we simply store 1
  else max of dp[j] + 1
*/
