/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: 

class Solution{
public:
    int minAddToMakeValid(string S){
        
        int result = 0;
        stack<char> st;
        
        for(auto ch: S){
            if(ch == '('){
                stack<char> empty;
                if(!st.empty() && st.top() == ')'){
                    result += st.size();
                    swap(st, empty);
                }                    
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
            }
        }
        result += st.size();
        
        return result;
    }
};

/*
Every time we encounter '('
    if top of stack is ')' ->   that means we are following the incvalid sequence
                                so we simply add the size of stack into result
                                and make the stack empty (we have processed the prev data)
        we push '(' into stack.
    
Every time we encounter ')'
    if top of stack is '(' ->   we are following the right sequence
                                so we pop the top
    else we push the ')', as it is invalid and has to be processes later.
*/


// ********************************************** Space Optimization ***********************************************************

class Solution{
public:
    int minAddToMakeValid(string S){
        
        int result = 0;
        int balance = 0;
        
        for(auto ch: S){
            balance += (ch == '(') ? 1: -1;
            if(balance == -1){
                result++;
                balance = 0;
            }
        }
        result += balance;
        
        return result;
    }
};

/*
Keep track of the balance of the string: the number of '(' is minus the number of ')'. 
A string is valid if its balance is 0, plus every prefix has non-negative balance.

Balance must be 0 before current char ->
    If balance is -ve we must add '(' to it.
    If balance is +ve we must add ')' to it.
    
At last we can add number-of-faults and Balance.
*/
