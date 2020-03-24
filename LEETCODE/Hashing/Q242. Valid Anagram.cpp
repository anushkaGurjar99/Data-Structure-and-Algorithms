/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t){
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> m;
        
        for(auto character: s)
            m[character]++;
        
        for(auto character: t){
            if(m[character] == 0)
                return false;
            m[character]--;
        }
        
        return true;
    }
};


// create a hashMap that keeps count of each letter of "s"
// loop through "t", decrement the char in hashMap (if the count is already 0, then return false)
