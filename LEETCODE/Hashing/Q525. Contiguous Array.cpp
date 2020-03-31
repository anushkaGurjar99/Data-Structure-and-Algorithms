/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/contiguous-array/

// Similar problme: max subarray sum equals to K
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2)
            return 0;
        
        unordered_map<int, int> mapp;
        
        int marker = 0;
        int result = 0;
        
        mapp[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            
            (nums[i] == 0) ? --marker : ++marker;
            
            auto itr = mapp.find(marker);
            
            if(itr != mapp.end())
                result = max(result, i - itr->second);
            else
                mapp[marker] = i;
        }
        
        return result;
    }
};

/*
HASH MAP technique:
    Take a var 'marker'.
    Increment the marker if 1 encountered
    Decrement the marker if 0 encountered
    
    keep updating the marker in Hash <marker, index>.
    (If marker exist in hash then store the difference (Value - current Index) else store it in hash.)
*/
