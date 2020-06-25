/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/word-break/

class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
        
        vector<bool> marker(s.size() + 1, false);
        marker[0] = true;
        
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                string curr = s.substr(j, i - j);
                if(marker[j] && words.find(curr) != words.end()){
                    marker[i] = true;
                    break;
                }
            }
        }
        return marker[s.size()];
    }
};

/*
The idea is the following:
    marker is an array that contains booleans (position starts with 1)
    marker[i] is True if 
        marker[j] is true AND (dictionary has segement that starts with s[j + 1] and ends at s[i])
        marker[0] is also True at the beginning of the word

Example:
s = "leetcode"
words = ["leet", "code"]

marker[4] is True because 
    "leet" is element of dictionary (that means s[1] to s[4] found) AND marker[0] is also true

marker[8] is True because 
    "code" is element of dictionary (that means s[5] to s[8] found) AND marker[4] is True
*/

