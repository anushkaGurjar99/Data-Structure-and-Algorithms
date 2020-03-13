/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); ){
            int numToBeSwapped = nums[i] - 1;
            
            if((nums[i] != i+1) && (nums[numToBeSwapped] != nums[i])){
                //value not matched from index+1 && required pos doesn't have desired value
                
                int swap = nums[i];
                nums[i] = nums[numToBeSwapped];
                nums[numToBeSwapped] = swap;
                
            }
            else{
                i++;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1)
                result.push_back(i+1);
        }
            
        return result;
    }
};
// swapping elements to their indexes.

/*
Another approach (Negation)
works only when unsigned int is permissible
//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/375581/C%2B%2B-easy-to-understand-comments-(negate-seen-elements)
*/
