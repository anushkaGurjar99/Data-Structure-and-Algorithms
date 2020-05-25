/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/decode-ways/

class Solution{
public:
    int numDecodings(string s){
        
        if(s.size() == 0 || s[0] == '0')
            return 0;
        
        vector<int> ways(s.size(), 1);
        
        for(int i = 1; i < s.size(); i++){
            
            if(s[i] == '0' && (s[i - 1] > '2' || s[i - 1] < '1'))
                return 0;
            
            if(s[i] == '0' || s[i - 1] == '0'){
                ways[i] = i < 2 ? 1 : ways[i - 2];
                continue;
            }
            
            int concat = (s[i - 1] - '0') * 10;
            concat += s[i] - '0';
            
            int x = i < 2 ? 1 : ways[i - 2];
            ways[i] = concat > 26 ? ways[i - 1] : ways[i - 1] + x;       
        }
        
        return ways[s.size() - 1];
    }
};


/*
Intution:
    this problem is similar to Fibo series problem except some edge cases
    
    Cases:-
        Non-Zero case:
            (*)
            if the number is compatible in concatination with prev digit 
            (which means it is comatible with both prev and prev to prev)
                then add prev 2 ways for current ways
                    1   2   1   2
                    1   2   3   5
            else   
                copy prev way for current way
                    9   9   9
                    1   1   1
                
        Zero case: 
            if zero is compatible with last digit, add its prev to prev ways (as prev is distroyed by 0)
                    1   1   1   0
                    1   2   3   2
                    
                    1 0
                    1 1     (*)

* :- if prev to prev does not exist, consider 1
*/
