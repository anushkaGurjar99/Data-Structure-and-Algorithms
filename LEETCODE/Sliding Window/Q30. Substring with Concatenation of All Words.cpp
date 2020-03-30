/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;
        
        if(words.size() == 0 || s == "" || (words[0].size() * words.size()) > s.size())
            return result;
        
        unordered_map<string, int> count;                     // count of each word of words vector
        for(auto word: words)
            count[word]++;
                
        int wordsLen = words[0].size() * words.size();        // length of whole array
        int start = 0;
        int end = wordsLen - 1;                               // window size
        int sizeOfAWord = words[0].size();          
        unordered_map<string, int> save = count;              // save the COUNT as we will be updating it
        
        while(end < s.size()){
            
            int visited = 0;
            string word = s.substr(start, sizeOfAWord);
            
            auto itr = count.find(word);
            if(itr != count.end()){
                visited++;
                count[word]--;
                while(visited < wordsLen){
                    start += sizeOfAWord;
                    word = s.substr(start, sizeOfAWord);
                    itr = count.find(word);
                    if(itr != count.end() && itr->second > 0)
                        count[word]--;
                    else
                        break;
                    visited++;
                }
                if(visited == words.size())
                      result.push_back(end - wordsLen + 1);
            }
            end++;      
            start = end - wordsLen + 1;
            visited = 0;
            count = save;
        }
        
        return result;
    }
};

/*
Approach: Slidind Window

store all words[i] with their occurance in hashMap COUNT

maintain a window of length "sum of length of all words[i]"
START and END denote the position of current window. 

loop throught the string "s"
{
    If we encounter the word in our window, then we will check for other words
            (while doing this we will maintain number of visited nodes)

            if our visited words == size of <words>, then we will store the start position

    each time we will increment out window by 1 from START as well as from END
}
*/

