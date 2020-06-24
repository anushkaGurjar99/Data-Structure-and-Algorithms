/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution{
public:
    string fractionToDecimal(int numerator, int denominator){
        
        if(numerator == 0)
            return "0";
        
        bool neg = (numerator < 0 ^ denominator < 0) ? true: false;
        
        long x = abs(numerator);
        long y = abs(denominator);
        
        string result = to_string(x / y);
        
        if(x % y != 0)
            result += "." + getFraction(x % y, y);
        
        result = (neg) ? "-" + result : result;
        return result;
    }
    
    string getFraction(long rem, long div){
        string result;
        unordered_map<long, int> m;
        int pos = 0;
        
        while(rem != 0){
            if(m.find(rem) == m.end()){
                m[rem] = pos++; 
            }
            else{
                result.insert(m[rem], "(");
                result.push_back(')');
                break;
            }
            
            rem *= 10;
            char ch = '0';
            
            if(rem >= div){              
                ch = '0' + (rem / div);                 
                rem %= div;                             
            }
            
            result.push_back(ch);
        }
        
        return result;
    }
    
};

/*
Store the reminder and corrosponding position into map

Keep divind the valid-rem
    case1: rem == 0, If it gets completely divided
    case2: If rem gets repeat then adjust the bracket (break)
    
If rem is not-valid
    rem = 1, div = 123456
    : Keep mul rem with 10 to make it valid and add 0'z into result 
*/
