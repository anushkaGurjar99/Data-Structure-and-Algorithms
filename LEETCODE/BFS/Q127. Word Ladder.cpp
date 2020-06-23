/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/word-ladder/

class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        
        int result = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        unvisited.erase(beginWord);
        
        while(!q.empty()){            
            for(int i = q.size(); i > 0; i--){
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                    return result;         
                
                for(int j = 0; j < word.size(); j++){
                    char c = word[j];
                    for(int k = 0; k < 26; k++){
                        word[j] = 'a' + k;
                        if(unvisited.find(word) != unvisited.end()){
                            q.push(word);
                            unvisited.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }
            result++;
        }
        
        return 0;
    }
};

/*
BFS approach -

Store the beginWord in queue.                                               Level 1
In next iteration store the word that were Ladder of Level 1 words          Level 2
Keep creating levels till target is found (return ladder length) or no Ladder left (return 0).

Maintain an Unvisited set which stores all words of array.
    How would you find next Ladder ?
        For each current word (traverse Qsize):
            Try all possible combinations by changing the place value.
            If the combination exist in out Unvisited set -> store it into Queue and remove from set.

    By this we will be creating Levels in Queue. and No string will be repeated as Ladder.
    
Example:
                            hit                     L1
                             |
                            hot                     L2
                           /   \
                         dot   lot                  L3
                          |     |
                         dog   log                  L4
                          |
                         cog                        L5
*/

