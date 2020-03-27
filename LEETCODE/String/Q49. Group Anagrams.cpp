/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/group-anagrams

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> m;
        
        for(string curr : strs){
            string temp = stringSort(curr);
            m[temp].push_back(curr);
        }
        
        for(auto key : m)
            anagrams.push_back(key.second);

        return anagrams;
    }
        
private:
    
    // since the string only contains lower-case alphabets, we can sort them using counting sort to improve the time complexity.
    string stringSort(string s){
        
        int counter[26] = {0};
        
        for(char c : s)
            counter[c - 'a']++;
        
        string t;
        
        for(int i = 0; i < 26; i++)
            t += string(counter[i], i + 'a');
        
        return t;
    }
};
