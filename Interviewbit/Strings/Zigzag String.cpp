/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string s, int numRows){
    if(numRows <= 1)
        return s;
        
    vector<string> level (numRows, "");
    string result = "";
        
    int curr = 0;
    int step = 0;
            
    for(int i = 0; i < s.size(); i++){
        
        level[curr].push_back(s[i]);
            
        if(curr == 0)
            step = 1;
        else if(curr == numRows - 1)
            step = -1;
        
        curr += step;
    }
        
    for(auto itr: level)
        result += itr;
        
    return result;
}

/*
Create numRows string vectors and push the characters
Then push the vectors into Result.
*/

// ********************************************* SCAN ONE LEVEL AT A TIME *********************************************

string getCharacter(string s, int& curr, int level){
    curr += (level - 1) + (level - 1 - 1) + 1;
    string res = "";
    return (curr < s.size()) ? res+s[curr] : res;
}

string Solution::convert(string s, int numRows){
    if(numRows <= 1)
        return s;
        
    string result = "";
    int limit = s.size();
    int level = 0;
        
    while(result.size() < limit){
        
        int curr = level;
        result += s[curr];
        int column = 0;
            
        while(curr < limit){
                
            if((column % 2 != 0 && level > 0) || level+1 == numRows)
                result += getCharacter(s, curr, level + 1);                   // upper
                
            else if(column % 2 == 0 || level == 0)
                result += getCharacter(s, curr, numRows - level);             // lower
            
            column++;
        }
            
        level++;
    }
        
    return result;
}

/*
Observation: 
First Level is expanding only at Lower SIDE
Last Level is expanding only at Upper SIDE

Rest other levels are searching at both Upper and Lower SIDE 
                                (according to COL, odd COL = Upper, even COL = Lower side)

Based on current level and DIRECTION we are calculating the next element. (till Resulant array doesn't has equal element as Input array)
*/
