/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/add-and-search-word-data-structure-design/

class WordDictionary{
public:
    
    unordered_map<int, vector<string>> dict;
    
    WordDictionary(){}
    
    void addWord(string word){
        dict[word.size()].push_back(word);
    }
    
    bool search(string word){
        for(auto itr: dict[word.size()]){
            if(itr.size() != word.size())
                continue;
            
            for(int i = 0; i < word.size(); i++){
                if(word[i] != '.' && word[i] != itr[i])
                    break;
                if(i == word.size() - 1)
                    return true;
            }
        }
        return false;
    }
};

/*
Approach:
    addword: store length wise word into dictionary
    searchword: search wordLength into dictionary and match each dict[length][i] from word.
*/
    
