/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return nums.size();
        
        int prev = 0;
        int curr = 1;
        int next = 1;
        
        while(curr < nums.size()){
            
            // if curr == prev OR if curr element is same as prev updated element
            if(nums[curr] == nums[prev] || nums[curr] < nums[curr - 1]){
                int t = nums[next];
                
                while(next < nums.size() && t == nums[next])
                    next++;
                
                if(next == nums.size())
                    break;
                
                nums[curr] = nums[next];
                curr++;
                
                if(nums[curr] == nums[curr - 1]){         // if curr element is same as prev updated
                    prev = curr - 1;   
                    // 2,2,3   then 2,3,3 here curr = 2
                }
            }
            else{
                if(next == curr)                          // update next if it is at same pos as curr
                    next++;
                prev = curr;
                curr++;
            }
        }
        
        nums.resize(curr);             // resize the array, it will auto eliminate the extras
        return curr;
    }
};
