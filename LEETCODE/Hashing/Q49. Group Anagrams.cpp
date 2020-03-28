/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/group-anagrams/

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        
        if(strs.size() < 1)
            return {};
        
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> m;
        
        for(string curr : strs){
            string temp = curr;
            sort(temp.begin(), temp.end());
            m[temp].push_back(curr);
        }
        
        for(auto key : m)
            anagrams.push_back(key.second);

        return anagrams;
    }
};
