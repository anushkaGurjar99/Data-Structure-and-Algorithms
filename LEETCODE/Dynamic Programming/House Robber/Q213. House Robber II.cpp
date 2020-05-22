/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/house-robber-ii/

class Solution{
public:
    int rob(vector<int>& nums){
        
        if(nums.size() == 0)
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        int size = nums.size();    
        return max(setRobbery(nums, 0, size - 1), setRobbery(nums, 1, size));
    }
    
    int setRobbery(vector<int>& nums, int start, int size){
        
        int one = nums[start];
        int two = max(nums[start], nums[start + 1]);
        int curr = two;
                
        for(int i = start + 2; i < size; i++){
            curr = max(two, nums[i] + one);
            one = two;
            two = curr;
        }
        
        return curr;
    }
};

/*
Intution:
    Cases:
        If we include the first house then we can't include the last house
        If we include the last house then we can't include the first house
    
    Solution:
        pass1:  start the dp appraoch from first house (exclude the last house)
                By this we will get the max profit when we exclude last home
                
        pass2:  start the dp appraoch from second house (exclude the first house)
                By this we will get the max profit when we exclude first home
                
At last return whichever is the max robbery of both pass
*/
