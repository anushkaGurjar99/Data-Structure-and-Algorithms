/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size() == 0)
            return INT_MIN;
        
        int maxSum = nums[0];
        int tempSum=0;
        for(int i = 0; i < nums.size(); i++){
            tempSum += nums[i];
            maxSum = max(tempSum, maxSum);
            tempSum = max(tempSum, 0);
        }
        return maxSum;
    }
};

/*
Idea is very simple. Basically, keep adding each integer to the sequence until the sum drops below 0.
If sum is negative, then should reset the sequence.
*/
