/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/find-and-replace-pattern/

class Solution{
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern){
        
        vector<string> result;
        
        for(auto word: words){
            unordered_map<char, char> m;
            unordered_set<char> v;
            
            int j = 0;
            
            for(; j < word.size(); j++){
                char ch = pattern[j];
                
                if(m.find(ch) != m.end() && m[ch] != word[j])
                    break;
                else if(m.find(ch) == m.end() && v.find(word[j]) != v.end())
                    break;
                else
                    m[ch] = word[j];
                
                v.insert(word[j]);
            }
            
            if(j == word.size())
                result.push_back(word);
        }
        
        return result;
    }
};

/*
Approach:
    Map each char of pattern to words[i].
    Keep track of mapped char of pattern.
    Keep track of visited char of words[i], no same char of words[i] is mapped to diff char of pattern 

    Conditions:
        if p[i] is mapped to w[j], now we found current char is not equals to w[j].        
        else if p[i] is not mapped to curr char, but current char is already mapped another char of p.
        else we store the p[i] = w[i]
        
    if whole words[i] is searched, then append it into result.
*/


