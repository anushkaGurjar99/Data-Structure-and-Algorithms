/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution{
public:
    string minRemoveToMakeValid(string s){
        
        int balance = 0;
        string result;
        
        for(auto ch: s){
            if(isalpha(ch)){
                result.push_back(ch);
                continue;
            }
            
            (ch == '(') ? ++balance : --balance;
            
            if(balance >= 0)
                result.push_back(ch);
            else
                balance = 0;
        }
        
        removeFromLast(result, balance);
        
        return result;
    }
    
    void removeFromLast(string& result, int balance){
        while(balance > 0){
            for(int i = result.size() - 1; i >= 0; i--){
                if(result[i] == '('){
                    result.erase(i, 1);
                    break;
                }
            }
            balance--;
        }
    }
};

/*
    either you will remove Closing para     (wherever mismatched)
        OR
    you will remove Opening para            (from end of string)
*/

