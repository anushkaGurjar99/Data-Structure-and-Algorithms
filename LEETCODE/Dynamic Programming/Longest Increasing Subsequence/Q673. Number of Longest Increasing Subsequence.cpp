/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution{
public:
    int findNumberOfLIS(vector<int>& nums){
        
        if(nums.size() <= 1)
            return nums.size(); 
        
        vector<int> LIS(nums.size(), 1);                // LIS length
        vector<int> countLIS(nums.size(), 1);
        int longest = 1;
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(LIS[i] < LIS[j] + 1){
                        LIS[i] = LIS[j] + 1;
                        countLIS[i] = countLIS[j];
                    }
                    else if(LIS[i] == LIS[j] + 1){
                        countLIS[i] += countLIS[j];
                    }
                }
            }
            longest = max(longest, LIS[i]);
            //cout<<"\n"<<LIS[i]<<"  "<<countLIS[i];
        }

        int result = 0;
        for(int i = 0; i < LIS.size(); i++){
            if(LIS[i] == longest)
                result += countLIS[i];
        }
        
        return result;
    }
};

/*
2 Arrays LIS[n] and countLIS[n] to record the maximum length of IS and the coresponding number of these
sequence which ends with nums[i], respectively. That is:
    LIS[i]: the length of the LIS which ends with nums[i].
    countLIS[i]: the number of the LIS which ends with nums[i].

Then, the result is the sum of each countLIS[i] while its corresponding LIS[i] is of maximum length.
*/

