/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/divide-two-integers/

class Solution{
public:
    int divide(int dividend, int divisor){   
        
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
        long result = 0;
        long num = labs(dividend);
        long div = labs(divisor);
        
        while(num >= div){
            int temp = 1;
            long x = div;
            while((x << 1) <= num){
                x <<= 1;
                temp <<= 1;
            }
            num -= x;
            result += temp;
        }
        
        return sign * result;
    }
};

/*
Appraoch:
    left shift the divisor till it can divide the divident
    as soon as it goes invalid -> 
        subtract the divided part from the number (x)
        update the result by adding how-many-times-it-was-divides (temp)
        
    Follow the same procedure on remaining number
   
   
For ex: num = 100,  divisor = 4
    
    4   8  16  32   64  (256)       => x
    1   2  4    8   16              => temp
    
    result = 16;
    num: 100 - 64 = 36
    
    
    4   8   16  32  (64)            => x
    1   2   4   8                   => temp
    
    result = 16 + 8;
    num: 36 - 32 = 4
    
    
    4   (8)                         => x
    1                               => temp
    
    result = 16 + 8 + 1
    num: 4 - 4 = 0
*/


