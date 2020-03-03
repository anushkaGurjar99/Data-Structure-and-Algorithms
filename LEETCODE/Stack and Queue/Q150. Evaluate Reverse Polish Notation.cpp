/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        
        for(auto token: tokens){
            int a,b;
            if(token == "+"){
                a = result.top();
                result.pop();
                b = result.top();
                result.pop();
                result.push(b + a);
            }
            else if(token == "-"){
                a = result.top();
                result.pop();
                b = result.top();
                result.pop();
                result.push(b - a);
            }
            else if(token == "*"){
                a = result.top();
                result.pop();
                b = result.top();
                result.pop();
                result.push(b * a);
            }
            else if(token == "/"){
                a = result.top();
                result.pop();
                b = result.top();
                result.pop();
                result.push(b / a);
            }
            else{
                int s = atoi(token.c_str());
                result.push(s);   
            }
        }
        
        return result.top();
    }
};
