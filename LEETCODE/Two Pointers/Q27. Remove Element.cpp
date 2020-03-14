/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-element

/* Two Pointer Approach*/
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

/*  Brute force Approach: O(n2) time
    for each nums[i] == val find the next element which is != val and swap both */

/*  Extra space Approach: O(n) time, O(n) space
    use a stack to store the desired elements (keep a count of elements) 
    rezise nums to the count and resotre elements by poping from stack */
