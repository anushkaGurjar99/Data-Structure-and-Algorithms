/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits){
        
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> s;
        vector<string> res;
        
        for(int i = 0; i < digits.size(); i++){
            if(m.find(digits[i]) != m.end())
                s.push_back(m[digits[i]]);
        }        
        
        backtrack(s, res, "", 0);
        return res;
    }
    
    void backtrack(vector<string>& s, vector<string>& res, string curr, int i){
        
        if(curr.size() == s.size()){
            if(curr != "")
                res.push_back(curr);
            return;
        }
        
        for(auto ch: s[i])
            backtrack(s, res, curr + ch, i + 1);
    }
};

/*
    "s" is the vector of corrosponding digit's character set (2 = "abc", 3 = "def" and so on..)
    
    
    letter combination must have s.size() characters.
    so we just need to make combinations of 1st digit with all digits.
    
    tree structure : string = "23"
    
                                    
                        /           |           \
                        a           b           c
                     /  |  \      /  |  \    /  |  \
                    ad  ae  af   bd  be bf   cd ce  cf
*/



