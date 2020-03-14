/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end){
            while(start <= end && nums[start] != val)
                start++;   
            
            while(end >= 0 && nums[end] == val)
                end--;
            
            if(start <= end){
                nums[start] = nums[end];
                start++;
                end--;
            }
        }
        
        // start denotes the next index (so as newArray size)
        // end denotes the index to be replaced
        
        nums.resize(start);
        
        return start;
    }
};
// Two pointer approach
