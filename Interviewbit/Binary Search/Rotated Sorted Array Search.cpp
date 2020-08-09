/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B){
    int left = 0;
    int right = A.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(A[mid] == B)
            return mid;
            
        if(A[left] < A[mid]){
            if(B >= A[left] && B < A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else{
            if(B > A[mid] && B <= A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    
    return -1;
}

/*
    target = 10;
    
    80   90   100  10   20   30   40   50   60   70 
    0    1     2   3    4    5    6     7   8    9
                    
    left  =  0      0
    right =  9      3
    mid   =  4      1....and so on.
    
basically check if mid is same as target
if not then,
    check which part of array is sorted left-to-mid or mid-to-right
    check target in sorted part if in range else search unsorted part
*/

// ********************************************************************************************************************************************

int Solution::search(const vector<int> &nums, int target) {

    int l = 0;
    int r = nums.size();
        
    while(l < r){
        int mid = (r - l)/2 + l;
        int comparator = nums[mid];
        
        // if: Checking if both target and nums[mid] are on same side.
        // else: Trying to figure out where nums[mid] is and making comparator as -INF or INF

        if((target < nums[0] && nums[mid] < nums[0]) || (target >= nums[0] && nums[mid] >= nums[0]))    // [< case ] means an 2 incr seq,  [ >= case ] 1 incr seq
            comparator = nums[mid];                                                                     
        else                                                                                            // rotation starts from [0]th element 
            comparator = target < nums[0] ? INT_MIN : INT_MAX;
        
        if(target == comparator) 
            return mid;
            
        if(target > comparator)            
            l = mid+1;            
        else
            r = mid;
    }
    return -1;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me
