/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/permutation-in-string/

class Solution{
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size() > s2.size())
            return false;
        
        vector<int> target(26, 0);
        countFrequency(target, s1, s1.size());
            
        vector<int> source(26, 0);
        int limit = s1.size() - 1;
        int i = limit;
        countFrequency(source, s2, limit);
            
        while(i < s2.size()){
            source[s2[i] - 'a']++;                // increment the window length
            
            if(source == target)                  // compare both windows
                return true;
            
            int pos = s2[i - limit] - 'a';        // i - limit th char should be decremented 
            source[pos]--;                        // remove outdated from window
            
            i++;
        }        
        return false;
    }
    
    void countFrequency(vector<int>& count, string& str, int limit){
        int i = 0;
        while(i < limit){
            count[str[i] - 'a']++;
            i++;
        }
    }
};

// concept similar to sliding window method
