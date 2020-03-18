/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.empty())
            return 0;
        
        unordered_multimap<char, int> uniques;
        int count = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++){
            auto itr = uniques.find(s[i]);
            
            // element not found || element found but it wasn't in our CURRENT window
            if(itr == uniques.end() || (itr != uniques.end() && i - count > itr->second)){
                count++;
                result = max(count, result);
            }
            else{
                // no. of elements in CURRENT window will be difference of curr element and duplicate 
                count = (i - itr->second);              
            }
            
            // insert the element in CURRENT window
            uniques.insert({s[i], i});
        }
        
        return result;
    }
};

