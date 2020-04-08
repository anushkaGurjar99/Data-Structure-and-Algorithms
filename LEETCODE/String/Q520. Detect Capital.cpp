/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/detect-capital/

class Solution{
public:
    bool detectCapitalUse(string word){
        
        for(int i = 1; i < word.size(); i++){
            if(isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i])) 
                return false;
        }        
        return true;
    }
    
};
/* 
1~n must be the same, (0 lower, 1-n supper) is not the case!
*/

// ****************************************************************************************************************************

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
