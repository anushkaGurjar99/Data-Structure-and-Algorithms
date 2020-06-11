/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k){
        int sum = 0;
        int maxNum = 0;
        for(int num : nums){
            sum += num;
            maxNum = max(maxNum, num);
        }
        
        if(sum % k != 0 || maxNum > sum / k)
            return false;

        vector<bool> visited(nums.size(), false);
        int target = sum / k;    
        
        return backtrack(nums, k, visited, target, 0, 0);
    }
    
    bool backtrack(vector<int>& nums, int k, vector<bool> visited, int& target, int currSum, int index){
        if(k == 0)
            return true;

        if(currSum == target)
            return backtrack(nums, k - 1, visited, target, 0, 0);
        
        for(int i = index; i < nums.size(); i++){
            if(!visited[i] && currSum + nums[i] <= target){
                visited[i] = true;
                if(backtrack(nums, k, visited, target, currSum + nums[i], i + 1))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};

/*
FLOW: 

Outer recursion on k subsets:
    Base case: k == 0
    Recursive case: k > 0 
				// Inner recursion on individual subset
				Base case: currSum == target (return to outer recursion)
				Recursive case: currSum < target
*/
