/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num){
        int n = num;
        long int power = 1;
        
        while(num){
            power *= 2;
            num >>= 1;
        }
        
        return power - n - 1;
    }
};

/*
  Calculate the power of 2 which is just greater than number
  subtract the number from power 
*/


// *********************************************** Method 2 *****************************************************

class Solution {
public:
    int findComplement(int num){
        int result = num;
        int pos = 0;
        int revertBit = 1;
        
        while(num){
            result ^= (revertBit << pos);
            pos++;
            num >>= 1;
        }
        
        return result;
    }
};

/*
  Store the number into some variable 
  then revert the bits one by one from last
*/
