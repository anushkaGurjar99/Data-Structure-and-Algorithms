/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s){
        
        stack<char> sequence;
        
        for(int i = 0; i < s.size(); i++){
            if(sequence.size() > 0){
                int top = sequence.top();
                if(top == '(' && s[i] == ')' || top == '{' && s[i] == '}' || top == '[' && s[i] == ']')
                    sequence.pop();
                else
                    sequence.push(s[i]);
            }
            else{
                sequence.push(s[i]);
            }
        }
        
        return sequence.empty();
    }
};


// ******************************************* Approach 2 *******************************************
class Solution {
public:
    bool isValid(string s){
        
        stack<char> sequence;
        
        for(auto ch: s){
            if(ch=='(' || ch=='{' || ch=='['){
                sequence.push(ch);
            }
            else{
                if(sequence.empty())
                    return false;
                char top  = sequence.top();
                if(top == '(' && ch == ')' || top == '{' && ch == '}' || top == '[' && ch == ']')
                    sequence.pop();
                else
                    return false;
            }
        }
        
        return sequence.empty();
    }
};

/*
Process each bracket of the expression one at a time.

If we encounter an opening bracket, push it onto the stack. This means we will process it later.

If we encounter a closing bracket, check the element on top of the stack. If the element at the top of the stack is 
an opening bracket of the same type, then we pop it off the stack and continue processing. Else, this implies an invalid expression.

In the end, if we are left with a stack still having elements, then this implies an invalid expression.
*/
