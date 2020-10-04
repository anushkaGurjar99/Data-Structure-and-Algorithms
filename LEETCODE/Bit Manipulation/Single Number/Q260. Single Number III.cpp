/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

Problem statement: https://leetcode.com/problems/single-number-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        
        int XOR = 0;
        for(auto num: nums)
            XOR ^= num;
        
        int lsb = (XOR & ~(XOR - 1));
        vector<int> res(2, 0);
        
        for(auto num: nums){
            if(num & lsb)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        
        return res;
    }
};

/*
Approach: Modified XOR

step1: XOR all numbers
        1     2    1    3    2    5
        001  010  001  011  010  101

        001
        010
        001
        011
        010
        101

    After XOR of all we will get this -
        011
        101     => 110
    
step2:  partition the numbers based on LSB   
        res[0] will be XOR of 1 at targetPos
            010 
            011
            010         => 011 
            
        res[1] will be XOR of 0 at targetPos
            001
            001
            101         => 101
*/
