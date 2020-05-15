/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/next-permutation/

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        
        bool isFound = false;
        int i = nums.size() - 2;
            
        for(; i >= 0; i--){
            int curr = nums[i];
            int next = nums[i + 1];
            
            if(curr < next){
                isFound = true;
                int j = i + 1;                                      // search from 
                while(j < nums.size() && nums[i] < nums[j])    
                    j++;
                
                swap(nums[i], nums[j - 1]);                         // j <= i, j+1 > i
                break;
            }
        }
        i = isFound ? 1 + i : 0;
        reverse(nums.begin() + i , nums.end());
    }
};
    
/*
Note that:
    Any sequence that is in DESC order, no next larger permutation is possible. 
        In this case just reverse the array.
    
    Otherwise - 
    1. Find the unsorted element pos i. (traverse from tail of array)
    2. Find the element from i+1 which is just greater than [i] (say j)
            
        For ex:
            1   4   2   5   4   3   1
                        .   .   .   .   (array[i] = 2)
            
            array[j] = 3
            
            swap [i] with [j]
            1   4   3   5   4   2   1
            
    3. now we reverse array from i+1 to array.size becuase that's what give us next permutation
            1   4   3   1   2   4   5
*/
