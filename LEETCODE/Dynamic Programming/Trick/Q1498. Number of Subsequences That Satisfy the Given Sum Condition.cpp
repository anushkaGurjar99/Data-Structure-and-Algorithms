/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        int left = 0;
        int right = nums.size() - 1;
        int mod = 1e9 + 7;
        
        vector<int> dp(nums.size(), 1);
        
        for(int i = 1 ; i < nums.size(); i++)
            dp[i] = dp[i - 1] * 2 % mod;
        
        while(left <= right){
            if(nums[left] + nums[right] > target)
                right--;
            else
                result = (result + dp[right - left++]) % mod;
        }
        
        return result;
    }
};

/*
Sort input A first,
For each A[i], find out the maximum A[j], that A[i] + A[j] <= target.

For each elements in the subarray A[i+1] ~ A[j],
    we can pick or not pick,
    so there are 2 ^ (j - i) subsequences in total.
    So we can update res = (res + 2 ^ (j - i)) % mod.

We don't care the original elements order,
    we only want to know the count of sub sequence.
    So we can sort the original A, and the result won't change.

Complexity
    Time O(NlogN)
    Space O(1)
*/


