/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
    void backtrack(vector<string>& result, string curr, int leftBracket, int rightBracket, int limit){
        if(leftBracket == limit && rightBracket == limit){
            cout<<"\n"<<curr;
            result.push_back(curr);
            return;
        }
        
        // keep track of validity
        if(leftBracket < limit)
            backtrack(result, curr + "(", leftBracket + 1, rightBracket, limit);
        if(rightBracket < leftBracket)
            backtrack(result, curr + ")", leftBracket, rightBracket + 1, limit);
    }
};


// ***************************************************************************************************************************

class Solution{
public:
    vector<string> generateParenthesis(int n){
        
        string open(n, '(');
        string close(n, ')');
        string s = open + close;
        
        vector<string> result;
        backtrack(s, result, 0);
        return result;
    }
    
    void backtrack(string& s, vector<string>& result, int index){
        if(index == s.size()){
            if(isValid(s))
                result.push_back(s);
            return;
        }    
        
        unordered_set<char> visited;
        for(int i = index; i < s.size(); i++){
            if(visited.find(s[i]) != visited.end())                 // skip duplicates
                continue;
            
            visited.insert(s[i]);
            swap(s[i], s[index]);
            backtrack(s, result, index + 1);
            swap(s[i], s[index]);
        }
    }
    
    bool isValid(string& s){
        int count = 0;
        for(auto itr: s){
            count += (itr == '(') ? 1 : -1;
            if(count < 0)
                return false;
        }
        return true;
    }
    
};

/*
Intution:
    create a string filled of "n" open braces and "n" losing braces (say string s)
    
    permute string s, start from 0th pos (say index)
    
    for each index permute its (index+1 to size) elements 
        when index reaches to end
            if s' forms a valid sequence then store it in result       
*/

