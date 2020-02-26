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

// ****************************** Approach 2: Non-Stack ******************************

class Solution {
public:
    string removeOuterParentheses(string S){
        string result;
        int flag = 0;
        
        for(int i = 0; i < S.size(); i++){
            
            bool bit = false;
            
            if(S[i] == '(')
                flag++;
            
            if(S[i] == ')'){
                if(flag == 1)
                    flag = 0;
                else
                    bit = true;
            }
            
            if(flag > 1){
                result += S[i];
            }
            
            if(bit == true)
                flag--;
        }
        
        return result;
    }
};
