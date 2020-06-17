/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/excel-sheet-column-number/

class Solution{
public:
    int titleToNumber(string s){
        
        if(s.size() == 0)
            return 0;
        
        int result = 0;
        
        for(auto ch: s){
            result *= 26;
            result += ch - 'A' + 1;
        }
        
        return result;
    }
};

/*
For every additional digit of the string, 
we multiply the digit value by 26^n where n is the number of digits it is away from the one's place. 

This is similar to how the number 254 could be broken down as this: 
(2 x 10 x 10) + (5 x 10) + (4). The reason we use 26 instead of 10 is because 26 is our base.

Example:- 
    BCM = (2 x 26 x 26)  +  (3 x 26)  +  (13)
*/
