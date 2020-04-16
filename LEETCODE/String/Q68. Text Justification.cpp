/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/text-justification/

#include<stdio.h>

class Solution{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        
        vector<string> result;
        result.push_back("");
        int currLine = 0;
        int wordsInCurrentLine = 0;
        
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            
            int lineLength = result[currLine].size();
            if(lineLength > 0)
                lineLength++;
            
            // add word into current line if enough space
            if(lineLength + word.length() <= maxWidth){         // +1 for space
                if(lineLength > 0)                              // add ' ' if cw is not first word
                    result[currLine].push_back(' ');
                result[currLine] += word;
                wordsInCurrentLine++;
            }
            
            // else justify the previous line and add word into new line
            else{
                justifyCurrentLine(result[currLine], maxWidth, wordsInCurrentLine);
                result.push_back("");
                currLine++;
                result[currLine] += word;
                wordsInCurrentLine = 1;
            }
        }      
        
        // justify last line
        if(result[currLine].length() < maxWidth){
            int s = maxWidth - result[currLine].length();
            string space(s, ' ');
            result[currLine] += space;
        }
        
        return result;
    }
    
    
    void justifyCurrentLine(string& line, int maxWidth, int wordCount){
        int totalSpace = maxWidth - (line.length());
        
        if(totalSpace == 0)
            return;
        
        int spacePerHead = (wordCount == 1) ? totalSpace : totalSpace / (wordCount - 1);
        int rem = (wordCount == 1) ? 0 : totalSpace % (wordCount - 1);
        string space(spacePerHead, ' ');
        
        int i = (wordCount == 1) ? 0 : 1;
        int j = 0;
        
        
        while(i < wordCount){
            while(j < line.size() && line[j] != ' ')
                j++;
            
            string extra = "";
            if(rem > 0)
                extra += ' ';
            line = line.substr(0, j) + space + extra + line.substr(j, line.length());
            j = j + spacePerHead + 1;   // move to start of next word
            i++;
            
            if(rem > 0){               
                rem--;
                j++;
            }
        }
    }
    
};


/*
Approach:
    1. take each word and check whether it fits into current line or not
    2. if it fits into current line then append a space and current word
    3. if it doesn't then justify the current line -> create new line and push the current word
    (keep updating the number of words in current line (say in wc))
    
    How would you justify the current line?
    1. if wc is 1 then add the whole additional space just after the word
    2. else divide the space between (wc - 1) area (sp) and calculate the reminder (r)
    3. add the sp and r after each word accordingly
*/
