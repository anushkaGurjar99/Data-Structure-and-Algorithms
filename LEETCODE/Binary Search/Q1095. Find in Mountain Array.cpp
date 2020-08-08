/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-in-mountain-array/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr){
        int peak = getPeak(mountainArr);
        int result = -1;
        int size = mountainArr.length();
        
        if(mountainArr.get(0) <= target && target <= mountainArr.get(peak))
            result = searchLeft(mountainArr, peak, target);
        
        if(result == -1 && mountainArr.get(peak + 1) >= target && target >= mountainArr.get(size - 1))
            result = searchRight(mountainArr, peak + 1, target);
        
        return result;
    }
    
    int getPeak(MountainArray &m){
        int left = 0;
        int right = m.length() - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            
            if(m.get(mid) < m.get(mid + 1))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return left;
    }
    
    int searchLeft(MountainArray &m, int right, int target){
        int left = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(m.get(mid) == target)
                return mid;
            
            if(m.get(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    
    int searchRight(MountainArray &m, int left, int target){
        int right = m.length() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(m.get(mid) == target)
                return mid;
            
            if(m.get(mid) < target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }
};

/*
    find the peak element
    if target exist in left subarray
        search left subarray
    if target is not found in left subarray and it can be in right subarray
        search right subarray
    
*/
