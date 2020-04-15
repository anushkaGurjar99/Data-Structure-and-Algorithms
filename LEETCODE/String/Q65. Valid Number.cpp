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
