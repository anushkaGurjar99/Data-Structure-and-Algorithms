/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution{
public:
    int peakIndexInMountainArray(vector<int>& A){
        
        int right = A.size() - 1;
        int left = 0;
        int result = 0;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(mid == 0 || A[mid] > A[mid - 1])
                result = mid;
            
            if(mid == 0 || A[mid] > A[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return result;
    }
};

/*
    [1, 7, 9, 15, 26, 5, 4, -1]
     0  1  2   3   4  5  6   7
     
     left  = 0      4       4       5
     right = 7      7       4       4
     mid   = 3      5       4    cond false
     
     peak  = 15             26     
     
Appraoch:
    Modified binary search.
    if we find the mid element smaller than result -> then we store it into result 
                                                      and move to right subarrray to search actual peak.
    else we seach the left subarray.
*/

// App2: see mountain array solution
