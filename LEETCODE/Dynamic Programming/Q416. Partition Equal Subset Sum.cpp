/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution{
public:
    bool canPartition(vector<int>& nums){
        
        int target = 0;
        int maxNum = nums[0];
        for(auto itr: nums){
            target += itr;
            maxNum = max(itr, maxNum);
        }
        
        if(target % 2 != 0 || nums.size() == 1 || maxNum > target / 2)
            return false;
        
        target /= 2;
        
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (target + 1, false));
        for(int i = 0; i < dp.size(); i++)
            dp[i][0] = true;        
        
        
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 1; j < target + 1; j++){
                
                dp[i][j] = dp[i-1][j];
                
                if(j >= nums[i-1])
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
            }
        }
        
        
        return dp[nums.size()][target];
    }    
};

/*
0/1 knapsack problem
dp[i][j] means,
    whether the specific sum j can be gotten from the first i numbers. 
    If we can pick such a series of numbers, dp[i][j] is true, otherwise it is false.

Base case: dp[0][0] is true; (zero number consists of sum 0 is true)

Transition function: 
    For each number, 
    
    if we don't pick it, dp[i][j] = dp[i-1][j],
    which means if the first i-1 elements has made it to j, dp[i][j] would also make it to j 
    (we can just ignore nums[i]). 
    
    if we pick it, dp[i][j] = dp[i-1][j-nums[i]],
    which represents that j is composed of the current value nums[i] and the remaining composed of 
    other previous numbers.
    
ref: tushar roy
*/
