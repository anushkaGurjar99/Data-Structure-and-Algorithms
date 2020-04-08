/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s){
        
        if(s.size() < 1)
            return 0;
        
        int len = 0;
        int i = s.size() - 1;
        
        while(i >= 0 && s[i] == ' ')            // skip all spaces from back
            i--;
        
        while(i >= 0 && s[i] != ' ')            // count the length of last word
            i--, len++;
        
        return len;
    }
};

