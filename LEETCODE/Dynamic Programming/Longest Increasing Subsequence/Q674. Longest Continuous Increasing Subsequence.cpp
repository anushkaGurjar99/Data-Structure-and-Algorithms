/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution{
public:
    int findLengthOfLCIS(vector<int>& nums){
        
        if(nums.size() == 0)
            return 0;
        
        int result = 1;
        int currLen = 1;
        
        for(int i = 1; i < nums.size(); i++){
            currLen = (nums[i] > nums[i - 1]) ? currLen + 1 : 1;
            result = max(currLen, result);
        }
        
        return result;
    }
};

/*
If current element is greater than prev
    include it into sequence
Else
    start the new sequence from current element
    
Keep a currentLen to maintain the current sequence length
At last return the maximum
*/
