/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums){
        
        if(nums.size() == 0)
            return INT_MIN;
        
        if(nums.size() == 1)
            return nums[0];
        
        int result = INT_MAX;
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right){
            
            int mid = left + (right - left) / 2;
            
            result = min(nums[mid], result);
            
            if(nums[mid] > nums[right])             // search RIGHT
                left = mid + 1;
            else                                    // search LEFT
                right = mid - 1;
        }
        
        return result;
    }
};

/*
Observaion:
    If middle element is greater than last element that means
        array is rotated
        elements before mid will also be greater than last element
        SO WE SHOULD SEARCH RIGHT SIDE
        
        5 7 9 1 3               mid = 9, right = 3  (mid > right) 
        
    else if middle element is smaller than right element that means 
        array may or may not be rotated
        there may exist more elements which is smaller than mid
        SO WE SHOULD SEARCH LEFT SIDE
        
        9 1 3 5 7               mid = 3, right = 7  (mid < right)
*/

// ******************************************** Better Approach *********************************************

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
        
        
        while(nums[left] > nums[right] && left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid - 1;
            
            //cout<<"\n"<<nums[left]<<' '<<nums[right];
        }        
        
        return min(nums[mid], nums[left]);
    }
};

/*
    if [left] element is greater than [right] then 
        find the MID element and split 
    else return the left element which is smallest
    
    How would you split?
    if MID element is greater than right
        All elements before MID are also greater than MID so Search RIGHT
    else
        There may exist smaller elements than MID at left side
*/

