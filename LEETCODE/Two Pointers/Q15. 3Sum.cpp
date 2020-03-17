/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end()); 
        
        for(int i = nums.size() - 1; i > 0; i--){
            int start = 0;
            int end = i - 1;
            
            while(start < end){
                if(nums[i] + nums[start] + nums[end] == 0){
                    
                    result.push_back({nums[i], nums[start], nums[end]});
                    
                    // remove duplicate
                    while(start < nums.size() - 1 && nums[start] == nums[start + 1])
                        start++;
                    
                    // remove duplicate
                    while(end > 0 && nums[end] == nums[end - 1])
                        end--;
                    
                    start++;
                    end--;
                    
                }
                else if(nums[i] + nums[start] + nums[end] > 0){
                    
                    // remove duplicate
                    while(end > 0 && nums[end] == nums[end - 1])
                        end--;
                    end--;
                    
                }
                else{
                    
                    // remove duplicate
                    while(start < nums.size() - 1 && nums[start] == nums[start + 1])
                        start++;
                    start++;
                    
                }
            }
            
            // remove duplicate
            while(i > 0 && nums[i] == nums[i - 1])
                i--;
        }
        return result;
    }   
};

/*
sudo code:
    
    1. Sort the array.
    2. Take three pointers (start, end, current)
        current = reverse array traversal 
        start = 0
        end = current - 1
    3. find combinations same as 'Triangle in array approach'
*/



// *********************************** Modular code of same approach (Time Limit Exceed) ****************************************

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end());    
        
        for(int i = nums.size() - 1; i >= 0; i--){
            int start = 0;
            int end = i - 1;
            while(start < end){
                if(nums[i] + nums[start] + nums[end] == 0){
                    result.push_back({nums[i], nums[start], nums[end]});
                    removeDuplicateFromLeft(nums, start);
                    removeDuplicateFromRight(nums, end);
                    start++;
                    end--;
                }
                else if(nums[i] + nums[start] + nums[end] > 0){
                    removeDuplicateFromRight(nums, end);
                    end--;
                }
                else{
                    removeDuplicateFromLeft(nums, start);
                    start++;
                }
            }
            removeDuplicateFromRight(nums, i);
        }
        return result;
    }
    
    void removeDuplicateFromLeft(vector<int> nums, int& index){
        while(index < nums.size() - 1 && nums[index] == nums[index + 1])
            index++;
    }
    
    void removeDuplicateFromRight(vector<int> nums, int& index){
        while(index > 0 && nums[index] == nums[index - 1])
            index--;
    }  
};
