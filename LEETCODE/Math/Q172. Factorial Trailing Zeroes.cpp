/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution{
public:
    int trailingZeroes(int n){
        
        int result = 0;
        
        while(n > 0){
            result += n/5;
            n /= 5;
        }
        
        return result;
    }
};

/*
10 is the product of 2 and 5. In n!, we need to know how many 2 and 5, 
and the number of zeros is the minimum of the number of 2 and the number of 5.

Since multiple of 2 is more than multiple of 5, the number of zeros is dominant by the number of 5.

    2147483647!
= 2 * 3 * ...* 5 ... *10 ... 15* ... * 25 ... * 50 ... * 125 ... * 250...
= 2 * 3 * ...* 5 ... * (5^1*2)...(5^1*3)...*(5^2*1)...*(5^2*2)...*(5^3*1)...*(5^3*2)... (Equation 1)
*/

