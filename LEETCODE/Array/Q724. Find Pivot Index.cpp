/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/
// Problem Statement: https://leetcode.com/problems/find-pivot-index/

class Solution{
public:
    int pivotIndex(vector<int>& nums){
        
        long numsSum = 0;
        
        for(auto num: nums)
            numsSum += num;
        
        int left = 0;
        int right = 0;
        
        for(int i = 0; i < nums.size(); i++){
            right = numsSum - left - nums[i];
            if(left == right)
                return i;    
            left += nums[i];
        }
        
        return -1;
    }
};

/*
pass 1: take sum of whole array.
pass 2: check leftSum and rightSum at each position.
        keep updating leftSum and rightSum.
*/

