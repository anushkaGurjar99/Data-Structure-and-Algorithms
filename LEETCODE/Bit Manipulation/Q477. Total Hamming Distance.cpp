/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/total-hamming-distance/

class Solution{
public:
    int totalHammingDistance(vector<int>& nums){
        
        if(nums.size() <= 0) 
            return 0;
        
        int res = 0;
        
        for(int i = 0; i < 32; i++){
            int setCount = 0;
            
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] & (1 << i))
                    setCount++;
            }
            
            int zeroCount = nums.size() - setCount;
            
            res += setCount * zeroCount;
        }
        
        return res;
    }
};

// https://leetcode.com/problems/total-hamming-distance/discuss/720409/Python-Bit-Manipulation-Explanation-with-Diagram
