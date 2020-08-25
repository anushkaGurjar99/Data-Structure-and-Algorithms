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

// ************************************************************************** Stack appraoch **************************************************************************

class Solution{
public:
    string minRemoveToMakeValid(string s){
        
        string temp;
        deque<int> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push_back(temp.size());
                temp.push_back('(');
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop_back();
                    temp.push_back(')');
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        
        string result;
        for(int i = 0; i < temp.size(); i++){
            if(!st.empty() && st.front() == i)
                st.pop_front();
            else
                result.push_back(temp[i]);
        }
        
        return result;
    }
};

/*
    Approach similar to 'reverse substring with each pair of parentheses'
    
    keep storing the char and opening bracket into temp string
    store temp.size() when ( encountered
    when ) encountered
        check is stack is not empty
            store the ) into temp and pop from stack
            
    At last remove all the extra opened bracket from string
*/


