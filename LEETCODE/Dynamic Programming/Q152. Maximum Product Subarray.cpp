/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums){
        
        if(nums.size() == 0)
            return 0;
        
        int maxPosTillNow = nums[0];
        int minNegTillNow = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int currPos = nums[i] * maxPosTillNow;
            int currNeg = nums[i] * minNegTillNow;
            maxPosTillNow = max(nums[i], max(currPos, currNeg));
            minNegTillNow = min(nums[i], min(currPos, currNeg));
            result = max(result, maxPosTillNow);
            
            //cout<<"\n"<<" : "<<maxPosTillNow<<" : "<<minNegTillNow<<" : "<<result;
        }

        return result;
    }
};

/*
Dry run these
[-5, -3, 1, -10], [-1, 0, 2, -3, -4, 6] 
*/

// ******************************************************* 2 Pass Solution ********************************************************
class Solution{
public:
    int maxProduct(vector<int>& nums){
        
        if(nums.size() == 0)
            return 0;
        
        int result = nums[0];
        int recentMaximum = 1;
        
        for(auto n: nums){
            recentMaximum *= n;
            result = max(result, recentMaximum);
            if(recentMaximum == 0)
                recentMaximum = 1;
        }
        
        recentMaximum = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            recentMaximum *= nums[i];
            result = max(result, recentMaximum);
            if(recentMaximum == 0)
                recentMaximum = 1;      
        }
        
        return result;
    }
};

/*
Intution:

Max product ignoring sign is simply the product of all the elements, as long there is no 0. 

but we have to consider the sign. so if product is negative, and we have odd number of negatives; 
then the max product is the bigger of:
    a) product of all excluding elements on the left, up to the first negative element.
    b) product of all excluding elements on the right, up to the last negative element.

so the solution is calculate product, 
    first from left to right, 
    then from right to left; 
    
during the process we are guaranteed to encounter the max product; 
whenever 0 is encountered, reset product to 1 and continue.
*/
