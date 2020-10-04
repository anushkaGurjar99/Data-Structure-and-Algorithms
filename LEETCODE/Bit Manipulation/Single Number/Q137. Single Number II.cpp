/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums){
        
        long val = 1;
        int res = 0;
        int turn  = 0;
        
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(auto num: nums)
                count += (num & (1 << turn)) ? 1 : 0;    
            
            res += (count % 3) ? val : 0;
            turn++;
            val *= 2;
        }
        
        return res;
    }
};

/*
A1: using map
A2: using sort

A3: (coded above)
    loop through all 32 bits
        mark the (non-multiple of 3) bit and keep adding it into result.        
*/

