/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution{
public:
    string reverseParentheses(string s){
        
        stack<int> st;
        string res;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(res.size());
            }
            else if(s[i] == ')'){
                int p = st.top();
                reverse(res.begin() + p, res.end());
                st.pop();
            }
            else{
                res += s[i];
            }
        }
        
        return res;
    }
};

/*
Keep adding char into res string by doing these operations

    store the length of res string when open bracket is found
        it will be start postion in res to-be-reversed
    if closing bracket is found
        reverse the string form top-of-stack to end-of-string
*/

