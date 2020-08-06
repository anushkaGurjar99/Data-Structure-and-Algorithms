/*
 * Author : Anushka Gurjar
 * Date   : Aug 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/replace-words/

class Solution{
public:
    string replaceWords(vector<string>& dict, string sentence){
        
        unordered_set<string> s(dict.begin(), dict.end());
        vector<string> words;
        getSentenceTokens(sentence, words);
        string result = "";
        
        for(auto word: words){
            string temp;
            
            for(int j = 0; j < word.size(); j++){
                temp.push_back(word[j]);
                if(s.find(temp) != s.end() || j == word.size() - 1){
                    result += temp + " ";
                    break;
                }
            }
        }
        
        result.pop_back();
        return result;
    }
    
    void getSentenceTokens(string& s, vector<string>& words){
        string word;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == ' '){
                words.push_back(word);
                word = "";
                continue;
            }
            word.push_back(ch);
        }
        words.push_back(word);
    }
};


/*
    Tokenize all words,
    check if substring of a word exist in dictSET.
        YES : replace it
        NO  : keep it as it is.
*/

