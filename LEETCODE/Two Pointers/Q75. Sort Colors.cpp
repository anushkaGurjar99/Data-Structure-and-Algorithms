/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sort-colors

// see leetcode notes for explanation
class Solution {
    public:
    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        int swap;
        
        while(mid <= high){
            if(nums[mid] == 1){             // incr the mid
                mid++;                     
            }
            else if(nums[mid] == 0){        // swap mid with low
                swap = nums[mid];
                nums[mid] = nums[low];
                nums[low] = swap;
                low++;
                mid++;                     // because we know before mid we have sorted elements
            }
            else{                          // swap mid with high
                swap = nums[mid];
                nums[mid] = nums[high];
                nums[high] = swap;
                high--;                    // mid can't be ince as swapped element has to be settle
            }
        } 
    }
};
