/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-palindromic-substring/

class Solution{
public:
    string longestPalindrome(string s){
        
        if(s.size() == 0)
            return "";
        
        vector<vector<bool>> marker(s.size(), vector<bool>(s.size(), false));
        string result = "";
        result.push_back(s[0]);
        
        for(int i = 0; i < s.size(); i++){
            marker[i][i] = true;
            
            for(int c = 0; c < i; c++){
                isPalindrome(marker, s, c, i);
                if(marker[c][i] && i - c + 1 > result.size())
                    result = s.substr(c, i - c + 1);
            }
        }
        
        return result;
    }
    
    void isPalindrome(vector<vector<bool>>& marker, string& s, int start, int end){
        if(start + 1 < end - 1){
            if(!marker[start + 1][end - 1])
                return;
        }
        
        if(s[start] == s[end])
            marker[start][end] = true;
    }
};
// explanation same as Q647.



// can be solved using backtracking..
