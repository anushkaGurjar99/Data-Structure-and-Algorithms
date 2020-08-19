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

// ********************************************************* Backtracking Appraoch ********************************************************************

class Solution{
public:
    bool canPartition(vector<int>& nums){
        
        int maxElement = INT_MIN;
        int sum = 0;
        
        for(auto num: nums){
            maxElement = max(maxElement, num);
            sum += num;
        }
        
        int half = sum / 2;
        
        if(maxElement > half || sum % 2 != 0)
            return false;
        if(maxElement == half)
            return true;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        return backtrack(nums, half, 0);
    }
    
    bool backtrack(vector<int>& nums, int currSum, int pos){
        if(currSum == 0)
            return true;
        
        if(pos == nums.size())
            return false;
        
        for(int i = pos; i < nums.size(); i++){
            if(currSum - nums[i] >= 0){
                if(backtrack(nums, currSum - nums[i], i + 1))
                    return true;
            }
        }
        
        return false;
    }
};

/*
    case1:  Max element is > sumOfAllElements / 2
            partition is not possible in this case
            
    case2:  Max element is same as target (target is half sum of array)
            
else: backtracking  
    each time we add an element into currSum and call the function recursively
    check if the currSum is same as Sum of half partition
*/
