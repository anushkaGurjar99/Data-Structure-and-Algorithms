/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word){
        
        if(word.size() < 2)
            return true;
        
        bool result;
        
        if(islower(word[0]))
            result = isAllSmall(word, 1);
        else
            result = islower(word[1]) ? isAllSmall(word, 1) : isAllCapital(word, 1);
            
        return result;
    }
    
    bool isAllSmall(string s, int start){
        for(int i = start; i < s.size(); i++){
            if(s[i] < 'a' || s[i] > 'z')
                return false;
        }
        return true;
    }
    
    bool isAllCapital(string s, int start){
        for(int i = start; i < s.size(); i++){
            if(s[i] < 'A' || s[i] > 'Z')
                return false;
        }
        return true;
    }
};
