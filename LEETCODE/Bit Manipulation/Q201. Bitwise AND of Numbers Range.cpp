/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution{
public:
    int rangeBitwiseAnd(int m, int n){
        int misMatch = 0;
        while(m != n){
            ++misMatch;
            m >>= 1;
            n >>= 1;
        }
        return m << misMatch;
    }
};
/*
Approch:
    count the number of misMatches 
    shift the matched number with misMatches
*/


// **********************************************************************************************************

class Solution{
public:
    int rangeBitwiseAnd(int m, int n){
        
        if(m == n || m == 0)
            return m;
        
        int result = 0;
        int discardVisited = 0;
        int num = m;
        long pow = 1;
        
        while(m){
            int placeValue = pow * (m & 1);
            if(placeValue){
                int rangeOfOne = num + (placeValue - discardVisited - 1);       // Exclude curr
                if(rangeOfOne >= n)
                    result += placeValue;
                discardVisited += placeValue;
            }
            m >>= 1;
            pow *= 2;
        }
        
        return result;
    }
};
/*
Since it is AND of a range, we don't need to check all numbers of given range
We just need to check all HIGH bits of first number

Ex.: Range is [3, 10]
    3   =   00011
    30  =   11110
    all pre zeros of 3, directly making the column AND = Zero.
    
Approach:
    starting from right side of Number
    
    If 1 is detected: 
        Calculate the COUNT that how long it can sustain in variable rangeOfOne
        if rangeOfOne is smaller than 'n'
            then it should not be included as after rangeOfOne numbers there will definitely be a 0
        else
            include the placeValue into result
        
        recompute the discarded numbers (numbers that are visited from these 1's)
    
    right shift the number by 1
*/
