/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/valid-number/

class Solution {
public:
    public:
    bool isNumber(string s) {
        int state = 0;
        vector<vector<int> > transTable = {
            {2, 1, -1, 3, 0, -1},       // Q0
            {2, -1, -1, 3, -1, -1},     // Q1
            {2, -1, 5, 4, 8, -1},       // Q2
            {4, -1, -1, -1, -1, -1},    // Q3
            {4, -1, 5, -1, 8, -1},      // Q4
            {7, 6, -1, -1, -1, -1},     // Q5
            {7, -1, -1, -1, -1, -1},    // Q6
            {7, -1, -1, -1, 8, -1},     // Q7
            {-1, -1, -1, -1, 8, -1}     // Q8
        };
        
        bitset<9> validStates("110010100"); 
        
        for(char c: s) {
            int type = inputType(c);
            state = transTable[state][type];
            if(state == -1) 
                return false;
        }
        
        return validStates[state];
    }
    
    int inputType(char c) { // use type ID as index to get next state in the transition table.
        if(isdigit(c)) 
            return 0; // T0
        if(c == '+' || c == '-') 
            return 1; // T1
        if(c == 'e') 
            return 2; // T2
        if(c == '.') 
            return 3; // T3
        if(c == ' ') 
            return 4; // T4
        else 
            return 5; // T5
    }
};

// https://leetcode.com/problems/valid-number/discuss/23798/Cleanest-C%2B%2B-Solution-using-DFA-(impress-your-interviewer-with-elegant-code!!)


// *********************************************** Without DFA *********************************************************

class Solution {
public:
    bool isNumber(string s){
        
        int i = 0;
        bool hasDigit = false;
        bool hasFraction = false;
        bool hasExponent = false;
        bool hasSignAfterExponent = false;
            
        skipSpaces(s, i);
        
        if(s[i] == '+' || s[i] == '-')
            i++;
        
        for(; i < s.length(); i++){
            char ch = s[i];           
            
            if(isdigit(ch) != 0){
                hasDigit = true;
                continue;
            }
            
            if(ch == ' '){
                skipSpaces(s, i);
                break;
            }
            
            if(ch == '.'){
                if(hasExponent || !isDotValid(s, i) || hasFraction)
                    break;
                hasFraction = true;
            }
            else if(ch == 'e'){
                if(!isExponentValid(s, i) || hasExponent || !hasDigit)
                    break;
                hasExponent = true;
            }
            else if(ch == '+' || ch == '-'){
                if(!hasExponent || hasSignAfterExponent || s[i-1] != 'e')
                    break;
                hasSignAfterExponent = true;
            }
            else{
                break;
            }
        }
        return (i == s.length() && hasDigit);
    }
    
    void skipSpaces(string s, int& i){
        while(i < s.size() && s[i] == ' ')
            i++;
    }
    
    // check both sides of 'e' both must be non empty and valid
    bool isExponentValid(string s, int i){
        int prev = i - 1;
        int next = i + 1;
        if(prev >= 0 && next < s.length()){
            if(s[next] == '+' || s[next] == '-')                        // next of 'e' can be a sign or digit
                next++;
            if(next >= s.length() || isdigit(s[next]) == 0)
                return false;
                    
            if(s[prev] == '.'){}                                        // prev of 'e' can be a '.' or digit
            else if(isdigit(s[prev]) == 0)
                return false;
        }
        else{
            return false;
        }   
        return true;
    }
    
    // validate both sides of '.', it must contain a 'e' or digit at either side.
    bool isDotValid(string s, int i){
        bool n = true;
        bool p = true;
        if(i+1 >= s.length() || (isdigit(s[i+1]) == 0 || s[i+1] == 'e'))                    // next can be 'e' or digit        
            n = false;
        if(i-1 < 0 || (isdigit(s[i-1]) == 0 || s[i-1] == 'e'))                              // prev can be 'e' or digit
            p = false;
                
        if(!n && !p)                                                                        // sides failed to be valid then invalid num
            return false;
        
        return true;
    }
};



