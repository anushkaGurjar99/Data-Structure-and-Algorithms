/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/word-break-ii/

void backtrack(string& s, unordered_set<string>& unique, vector<string>& result, string c, int index){
    if(index == s.size()){
        c.pop_back();
        result.push_back(c);
        return;
    }
        
    string current;
    for(int i = index; i < s.size(); i++){
        current.push_back(s[i]);
        if(unique.find(current) != unique.end())
            backtrack(s, unique, result, c + current + " ", i + 1);
    }
}

vector<string> Solution::wordBreak(string s, vector<string> &wordDict){
    unordered_set<char> one;
    unordered_set<char> two;
        
    for(auto itr: s)
        one.insert(itr);
        
    for(auto word: wordDict){
        for(auto itr: word){
            if(one.find(itr) != one.end())  
                two.insert(itr);
        }
    }
        
    if(one != two)
        return {};
        
    vector<string> result;
    unordered_set<string> unique(wordDict.begin(), wordDict.end());
    backtrack(s, unique, result, "", 0);
    return result;
}

/*
Preprocessing:
    If wordDict does not contains all the char of String s 
        then simply return empty array
    
    Else:
        1. Keep adding char to 'current' 
            (current is the word that has to be searched, we have already searched chars before current)
        2. If the search reaches end of strig
            store the combination into result
        3. Check for other combinations
*/
