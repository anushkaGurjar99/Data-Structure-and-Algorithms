/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> one;
        unordered_map<char,int> two;
        
        for(auto ch: s)
            one[ch]++;
        for(auto ch: t)
            two[ch]++;
        
        int diff = 0;
        
        for(auto i: one){
            int freq = i.second;
            char ch = i.first;
            if(two.find(ch) != two.end())
                diff += freq > two[ch] ? (freq - two[ch]) : 0;
            else
                diff += freq;
        }
        return diff;
    }
};

/*
 string s            string t
"leetcode"          "practice"

o = 1                   0
l = 1                   0
e = 3                   1
t = 1                   1
c = 1                   2
d = 1                   0
                        i = 1
                        p = 1
                        r = 1
                        a = 1
    
    occurances to convert string t into string s
    1 + 1 + 2 + 0 + (-1) + 1
*/   
    
    
// ******************************************** Using Single Map *******************************************************

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        
        for(auto ch: s)
            m[ch]++;
        for(auto ch: t)
            m[ch]--;
        
        int diff = 0;
        
        for(auto i: m){
            if(i.second > 0)
                diff += i.second;
        }
        
        return diff;
    }
};
