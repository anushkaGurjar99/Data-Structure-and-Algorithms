/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/range-sum-query-immutable/

class NumArray{
    vector<int> dp;
public:
    NumArray(vector<int>& nums){
        int size = nums.size();
        dp.resize(size + 1);
        
        for(int i = 0; i < size; i++)
            dp[i + 1] = dp[i] + nums[i];
    }
    
    int sumRange(int i, int j){
        return dp[j + 1] - dp[i];
    }
};

/*
    Create dp array of sum
        1   2  -3   2  -1   0   4
    0   1   3   0   2   1   1   5
    
    return dp[rightBoundary] - dp[unrequiredSum]    
*/
