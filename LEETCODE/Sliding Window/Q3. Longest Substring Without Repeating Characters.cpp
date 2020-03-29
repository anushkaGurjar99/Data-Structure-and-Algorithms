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
        int start = 0;
        int end = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++){
            auto itr = uniques.find(s[i]);
            
            if(itr != uniques.end() && itr->second >= start)
                start = itr->second + 1;
            
            end++;
            result = max(result, end - start);
            uniques.insert({s[i], i});
        }
        
        return result;
    }
};

/*
START and END denoting the begin and end of our current window

keep incr END in every iteration, check if s[i] already exist in CURRENT window then move START to
that occurance
*/


// *************************************************************************************************************

class Solution {
public:
    int lengthOfLongestSubstring(string A){
        
        unordered_map<char, int> m;
    
        int result = 0;
        int start = 0;

        for(int i = 0; i < A.size(); i++){

            auto itr = m.find(A[i]);
            if(itr != m.end() && itr->second >= start)
                start = itr->second + 1;

            result = max(result, i - start + 1);
            m[A[i]] = i;
        }

        return result;
    }
};

/*

(memory efficient: storing only recent occurance)

START and i denoting the begin and end of our current window

keep incr i in every iteration, check if s[i] already exist in CURRENT window then move START to
that occurance
*/

