/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string s) {

    stack<int> st;
    int len = 0;
    int result = 0;
    st.push(-1);
        
    for(int i = 0;i < s.size();++i){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(!st.empty()){
                len = i - st.top();
                result = max(result, len);
            }
            else{
                st.push(i);
            }
        }
    }
        
    return result;
}

/*
if s[i] = '(' 
    we push the index onto the stack

else
we pop the stack and use the current index minus the index at the top to be the current_length. 
we check against the max found so far and update if needed.
*/

