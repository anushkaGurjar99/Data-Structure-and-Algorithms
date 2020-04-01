/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T){
        short s = S.size() - 1;
        short t = T.size() - 1;
        
        while(s >= 0 || t >= 0){
            
            while( s >= 0 && S[s] == '#')
                skipHash(S, s);
            while(t >= 0 && T[t] == '#')
                skipHash(T, t);
            
            if(s == -1 && t == -1)                          // both pointing to end of string
                return true;
            
            if((s < 0 && t >= 0) || (s >= 0 && t < 0))      // if one string end before second
                return false;
            
            if(S[s] != T[t])                                // if characters are not same
                return false;
                
            s--;
            t--;
        }
        
        return true;
    }
    
    void skipHash(string str, short& pos){
        int countHash = 0;
        
        while(true){
            if(str[pos] == '#'){
                countHash++;
                pos--;
            }
            else{
                pos--;
                countHash--;
            }
            
            if(countHash == 0 || pos < 0)
                break;
        }
        
    }
};

/*
Intution:
    take 2 short (range 0 to 100), pointing to back of both strings. Say p1 and p2
    Set both pointers
        If any # encounered then move the pointer by number of hash count. 
        (repeat the skipping if # found in skipped elements, by number of hash found)
    compare p1 and p2
        If they are pointing to same char continue
        else return false
        
    at last return true which mean both pointers are at same pitch and string have same char sequence.
*/
