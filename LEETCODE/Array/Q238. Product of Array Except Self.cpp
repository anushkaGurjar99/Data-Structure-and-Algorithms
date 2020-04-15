/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        
        vector<int> result(nums.size(), 1);
        
        productLeftSubArray(result, nums);
        
        productRightSubArray(result, nums);
        
        return result;
    }
    
    void productLeftSubArray(vector<int>& result, vector<int> nums){
        int l = 1;
        for(int i = 1; i < nums.size(); i++){           // skip 0th element
            result[i] = l * nums[i - 1];
            l = result[i];
        }
    }
    
    void productRightSubArray(vector<int>& result, vector<int> nums){
        int r = 1;
        for(int i = nums.size() - 2; i >= 0; i--){      // skip last element
            r *= nums[i + 1];
            result[i] *= r;
        }
    }
};

/*
Observation:
    For each index we need to calculate left subarray(L) and right subarray(R) product 
    then multiply both L[i] and R[i] for each i.
    
       [1   2   3   4]
    L = 1   1   2   6
    R = 24  12  4   1
*/
