/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};

/*
Keep fliping the LSB in each iteration. because we know that (n & n-1) trick helps in removing LSB per itr.

    Ex: n = 1011 = 11
        
        itr1: n = 1010 = 10, count++
        itr2: n = 1000 = 8, count++
        itr3: n = 0000 = 0, count++
*/

// Approach 2: check linearly all 32 bits using a mask variable. (mask << 1 in each iteration)
