/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sort-colors

// see leetcode notes for explanation
class Solution {
    public:
    void sortColors(vector<int>& nums) 
    {
        int swap = 0;
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
    
        while(mid <= high){
            if(nums[mid] == 0){
                swap = nums[low];
                nums[low] = nums[mid];
                nums[mid] = swap;
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap = nums[high];
                nums[high] = nums[mid];
                nums[mid] = swap;
                high--;
            }
        }
    }
};
