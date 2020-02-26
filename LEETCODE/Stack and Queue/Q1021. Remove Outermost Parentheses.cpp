/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string S){
        string result;
        stack<char> sequence;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '('){
                
                sequence.push(S[i]);
                if(sequence.size() > 1)
                    result += S[i];
                
            }
            else{
                
                if(sequence.size() > 1)
                    result += S[i];       
                sequence.pop();
    
            }        
        }      
        return result;
    }
};
