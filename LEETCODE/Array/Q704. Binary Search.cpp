/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/binary-search/

class Solution{
public:
    int search(vector<int>& nums, int target){
        
        int left = 0;
        int right = nums.size();
        
        while(left < right){
            int mid = left + (right - left) / 2;
            //cout<<'\n'<<nums[mid];
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }        
        return -1;
    }
};

/*
Search left if target is smaller than mid
Search right if target is greater than mid

Return target if found else return -1
*/
