/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution{
public:
    vector<int> findDuplicates(vector<int>& nums){
        
        vector<int> result;
        int size = nums.size();
        
        for(int i = 0; i < size; i++){
            if(nums[i] != i + 1){
                int j = i;
                while(nums[j] != j + 1 && nums[nums[j] - 1] != nums[j])
                    swap(nums[j], nums[nums[j] - 1]);
            }
        }
        
        for(int i = 0; i < size; i++){
            if(nums[i] != i + 1)
                result.push_back(nums[i]);
        }
        
        return result;
    }
};

/*
Able to find duplicates that occur more than twice (Generalized)
Concept similar to 'first missing positive in array'

Pass1: We place each number to its respected index. 
Pass2: return the element which is not equals to (index + 1)
*/


// ************************************************************ Sign Manipulation ************************************************************

class Solution{
public:
    vector<int> findDuplicates(vector<int>& nums){
        
        vector<int> result;
        int size = nums.size();
        
        for(int i = 0; i < size; i++){
            int num = abs(nums[i]);
            if(nums[num - 1] > 0)
                nums[num - 1] *= -1;
            else
                result.push_back(num);
        }
        
        return result;
    }
};

/*
Since one element can appear at most twice so this approach would work.

Mark the visited element index -ve
If you find the element already -ve, that means it is already visited, so put it into result.
*/


