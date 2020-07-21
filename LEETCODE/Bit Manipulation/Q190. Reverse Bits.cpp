/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/reverse-bits/

class Solution{
public:
    uint32_t reverseBits(uint32_t n){
        
        uint32_t result = 0;
        
        for(int i = 0; i < 32; i++)
            result = (result << 1) + ((n >> i) & 1);
        
        return result;
    }
};
