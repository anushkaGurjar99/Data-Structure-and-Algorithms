/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        
        int size = nums.size();
        if(size == 0)
            return 0;
        
        int pos = 0;
        
        for(int i = 0; i < size; i++){
            if(pos < 2 || nums[i] != nums[pos - 2]){
                nums[pos] = nums[i];
                pos++;
            }
        }
        
        if(pos != size)
            nums.erase(nums.begin() + pos);
        
        return pos;
    }
};

/*
App1: Create new array 
      time, space = O(N)
      
App2: Two pointer

      one pointer is traversing the array,
      another pointer is overwriting the non-required elements.
*/

