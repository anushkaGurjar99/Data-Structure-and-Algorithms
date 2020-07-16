/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution{
public:
    
    int numSub(string s){
        
        int MOD = 1000000007;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0')
                continue;
            
            long counter = 0;
            while(i < s.size() && s[i] == '1')
                i++, counter++;
            
            i--;
            
            result += ((counter * (counter + 1)) / 2) % MOD;
        }
        
        return result;
    }
};

/*
    count the contigous 1s
    apply the formula and update the result.
*/

//*******************************************************************************************************************************************************
    
    int numSub(string s) {
        int res = 0, count = 0, mod = 1e9 + 7;
        for (char c: s) {
            count = c == '1' ? count + 1 : 0;
            res = (res + count) % mod;
        }
        return res;
    }

