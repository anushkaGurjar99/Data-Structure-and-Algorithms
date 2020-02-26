/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> sequence;
        string result;
        
        for(int i = 0; i < S.size(); i++){   
            if(sequence.empty()){
                sequence.push(S[i]);
                result += S[i];
            }      
            else{
                if(S[i] == sequence.top()){
                    sequence.pop();
                    result.pop_back();
                }
                else{
                    sequence.push(S[i]);
                    result += S[i];    
                }
            }
        }     
        
        return result;
    }
};

/*
If the stack is empty push curr into the stack.
else if the stack top is same as curr, pop the stack once.
else push curr into the stack.

Finally the elements in the stack is the answer in reverse order.
*/
