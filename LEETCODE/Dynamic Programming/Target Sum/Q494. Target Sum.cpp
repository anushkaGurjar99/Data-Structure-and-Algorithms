/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/target-sum/

class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int target){
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum < target || (target + sum) & 1)                      // sum < s OR sum + target is odd
            return 0;

        target = (target + sum) >> 1;
        cout<<target;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(auto n: nums){
            for(int i = target; i >= n; i--)
                dp[i] += dp[i - n];
        }
        
        return dp[target];
    }  
};
// https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation


// ***************************************************** Backtracking ******************************************************

class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int S){
        int result = 0;
        long temp = S;
        backtrack(nums, temp, result, 0);
        return result;
    }
    
    void backtrack(vector<int>& nums, long target, int& result, int i){
        if(i == nums.size()){
            if(target == 0)
                result++;
            return;
        }
        
        target += nums[i];
        backtrack(nums, target, result, i + 1);
            
        target -= nums[i] * 2;
        backtrack(nums, target, result, i + 1);
    }
};

/*
Check all combinations using backtracking,
    No for loop here because we are picking every element of array 
    Just with diff signs
*/


// ******************************************************* BFS (TLE) *********************************************************

class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int S){
        
        int result = 0;
        queue<int> q;
        q.push(S);
        int i = 0;
        
        while(i < nums.size()){
            int size = q.size();
            while(size-- > 0){
                int top = q.front();
                q.pop();
                q.push(top + nums[i]);
                q.push(top - nums[i]);
            }
            i++;
        }
        
        while(!q.empty()){
            result += (q.front() == 0) ? 1 : 0;
            q.pop();
        }
        
        return result;
    }
};

/*
    BFS approach:
    
    target = 3,  nums = [1,1,1,1,1]
    
                                    3
                         /                  \
                         4                    2                         num[0]
                    /        \           /           \
                    5         3          3            1                 nums[1]
                  /   \     /   \       /   \      /    \
                 6    4     4    2     4     2    2      0              nums[2]
                / \  / \   / \   / \   / \   / \   / \    / \           
               7  5  5  3  5  3  3  1  5  3  3  1  3  1  1  1           nums[3]
               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
               
               8  6  6  4  6  4  4  2  6  4  4  2  4  2  2  2
               6  4  4  2  4  2  2  0  4  2  2  0  2  0  0  0 
                  
*/
