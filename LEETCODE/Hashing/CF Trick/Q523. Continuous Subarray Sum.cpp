/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int cf = 0;
        int pre = 0;
        
        unordered_set<int> modk;
        
        for(int i = 0; i < nums.size(); i++){                                                                    
            cf += nums[i];
            int mod = (k == 0) ? cf : cf % k;      
            
            if(modk.count(mod))
                return true;
            
            modk.insert(pre);
            pre = mod;
        }    
        
        return false;
    }
};

/*
There is really no need to use map, the required length is at least 2, so we just need to insert the mod one iteration later.

one possible explanation: if two numbers (s1 and s2) have the same remainder , and the divisor is k , then s2-s1 must be divided by k , that's why the author store the previous remainder
*/
