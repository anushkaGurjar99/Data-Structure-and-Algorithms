/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s){
        
        if(s.size() < 2)
            return s;
        
        int start = 0;
        int end = s.size() - 1;
        
        const char* vowels = "aeiouAEIOU";
        
        while(start < end){
            
            while(strchr(vowels, s[start]) == nullptr && start < end)
                start++;
            
            while(strchr(vowels, s[end]) == nullptr && start < end)
                end--;
            
            swap(s[start], s[end]);
            start++;
            end--;
        }
        
        return s;
    }
};

// ***************************************************************************************************************

class Solution {
public:
    string reverseVowels(string s){
        
        if(s.size() < 2)
            return s;
        
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end){
            
            while(!isVowel(s[start]) && start < end)
                start++;
            
            while(!isVowel(s[end]) && start < end)
                end--;
            
            swap(s[start], s[end]);
            start++;
            end--;
        }
        
        return s;
    }
    
    bool isVowel(char ch){
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};
