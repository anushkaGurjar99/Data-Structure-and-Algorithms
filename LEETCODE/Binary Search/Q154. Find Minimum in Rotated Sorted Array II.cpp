/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums){
        
        if(nums.size() == 0)
            return INT_MIN;
        
        if(nums.size() == 1)
            return nums[0];
        
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while(left < right && nums[left] == nums[right])        
            right--;
        
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }
};

/*
Remove all duplicates of pivot from last then do usual BS.
Applying this will not generate confusion for SIDE Selection
*/

// **********************************************************************************************************************

class Solution{
public:
    int findMin(vector<int>& nums){
        
        if(nums.size() == 0)
            return INT_MIN;
        
        if(nums.size() == 1)
            return nums[0];
        
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if(nums[mid] < nums[right])
                right = mid;
            else 
                right--;
        }
        
        return nums[left];
    }
};

/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/167981/Beats-100-Binary-Search-with-Explanations
*/

