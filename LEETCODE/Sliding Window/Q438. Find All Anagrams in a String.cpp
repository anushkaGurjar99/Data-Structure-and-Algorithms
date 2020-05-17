/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.size() > s.size())
            return {};
        
        vector<int> p_count(26, 0);
        
        for (char c : p)
            p_count[c - 'a']++;
        
        vector<int> s_count(26, 0);
        
        vector<int> result;
        
        for (int i = 0; i + 1 < p.size(); i++)
            s_count[s[i] - 'a']++;
        
        for (int i = 0; i + p.size() <= s.size(); i++){
            char index = s[i + p.size() - 1];
            s_count[index - 'a']++;
            
            if (p_count == s_count)
                result.push_back(i);
            
            s_count[s[i] - 'a']--;
        }
        return result;
    }
};

