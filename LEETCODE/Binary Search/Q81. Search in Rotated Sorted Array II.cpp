/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution{
public:
    bool search(vector<int>& nums, int target){
        
        if(nums.size() == 0) 
            return false;
        if(nums.size() == 1) 
            return nums[0] == target;

        int l = 0;
        int r = nums.size()-1;

        while (l <= r){

            // skip duplicates from the left
            while(l < r && nums[l] == nums[l + 1])
                l++; 

            // skip duplicates from the right
            while(l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l + (r-l)/2;

            if(target == nums[mid])
                return true; 

            // right side is not sorted; go check left side
            if(nums[mid] > nums[r]){
                if(nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else                                         
                    l = mid + 1;

            }

            // left side is not sorted; go check right side
            else if(nums[l] > nums[mid]){
                if(nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else                                        
                    r = mid - 1;
            }

            // both side are sorted; there is no rotation
            else{
                if(target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};

// basically our pivot should be unique to make accurate selection
