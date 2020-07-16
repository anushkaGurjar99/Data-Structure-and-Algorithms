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
