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
            char next = s[i + p.size() - 1];
            s_count[next - 'a']++;
            
            if (p_count == s_count)
                result.push_back(i);
            
            s_count[s[i] - 'a']--;
        }
        return result;
    }
};
/*
(Same as sliding window.) (Keep track of in-window char and check it with p_count)
keep count of p-1 char in vector s_count(using next) and check it with p_count vector.
keep decrementing the not-in-range char count in s_count.
*/
