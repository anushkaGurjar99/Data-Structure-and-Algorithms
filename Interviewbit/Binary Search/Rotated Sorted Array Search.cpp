/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &nums, int target) {

    int l = 0;
    int r = nums.size() - 1;
        
    while(l <= r){
        int mid = (r - l)/2 + l;
        int comparator = nums[mid];
        
        // Checking if both target and nums[mid] are on same side.
        if((target < nums[0] && nums[mid] < nums[0]) || (target >= nums[0] && nums[mid] >= nums[0]))
            comparator = nums[mid];
        else
        // Trying to figure out where nums[mid] is and making comparator as -INF or INF
            comparator = target < nums[0] ? INT_MIN : INT_MAX;
        
        if(target == comparator) 
            return mid;
            
        if(target > comparator)            
            l = mid+1;            
        else
            r = mid-1;
    }
    return -1;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me
