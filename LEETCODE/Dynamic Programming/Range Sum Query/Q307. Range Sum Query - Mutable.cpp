/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/range-sum-query-mutable/

class NumArray{
    vector<int> dp;
    vector<int> arr; 
public:
    NumArray(vector<int>& nums){
        int size = nums.size();
        dp.resize(size + 1);
        dp[0] = 0;
        for(int i = 0; i < size; i++)
            dp[i + 1] = dp[i] + nums[i];
        arr.resize(size);
        arr = nums;
    }
    
    void update(int i, int val){
        int diff = val - arr[i];
        arr[i] = val;        
        for(int x = i + 1; x < dp.size(); x++)
            dp[x] += diff;
    }
    
    int sumRange(int i, int j){
        return dp[j + 1] - dp[i];        
    }
};

// update the whole dp array.
