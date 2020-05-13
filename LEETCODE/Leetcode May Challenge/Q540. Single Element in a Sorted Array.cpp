/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            
            int partner = mid % 2 == 0 ? nums[mid + 1] : nums[mid - 1];
            
            if(nums[mid] == partner)
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};

/*

Approach:
    if mid element is Even                  [10, 20, 20, 40, 40] mid = 2
        its pair must exist at mid + 1  
    if mid element is Odd                   [8, 12, 12] mid = 1
        its pair must exist at mid - 1

Intution:

The pairs which are on the left of the single element, will have the first element in an even position 
and the second element at an odd position. 
All the pairs which are on the right side of the single element will have the first position at an odd
position and the second element at an even position. Use 
this fact to decide whether to go to the left side of the array or the right side.
*/
