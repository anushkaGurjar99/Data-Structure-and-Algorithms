/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine){
        
        if(ransomNote.size() > magazine.size())
            return false;
        
        unordered_map<char, int> freq;
        
        for(auto ch: magazine)
            freq[ch]++;
        
        for(auto ch: ransomNote){
            if(freq.find(ch) != freq.end() && freq[ch] > 0)
                freq[ch]--;
            else
                return false;
        }
        
        return true;
    }
};

/*
pass 1: Count frequency of characters in Magazine
pass 2: Check the ransomNote character availability into Map
*/
