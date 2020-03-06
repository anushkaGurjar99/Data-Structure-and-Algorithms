/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> getMax;
        vector<int> result;
        int start = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            int flag = 0;
            
            while(true){                         // remove elements which are < current element as current will be max in respected case
                if(getMax.empty())
                    break;
                if(nums[getMax.back()] < nums[i] )
                    getMax.pop_back();
                else
                    break;
            }

            getMax.push_back(i);
            
            if(i+1 >= k){                        // cal range(loop through first k elements, then keep inserting front) {0-k, 1-(k+1)..}
                result.push_back(nums[getMax.front()]);
                start++;
            }
            
            if(getMax.front() < start)            // Delete the element if it is out of Range
                getMax.pop_front();
        }
        
        return result;
    }
};

/*
Appraoch : 
    check if arr[i] > Deque.back()
        if it is then delete elements from Deque back till arr[i] < Deque.back()
    Insert Element in Deque
    
    as Soon as we loop though first K elements we pop_front from Deque and store in result
    if the element at front of Deque is out of range then we delete that element
*/

// https://www.youtube.com/watch?v=5VDQxLAlfu0
