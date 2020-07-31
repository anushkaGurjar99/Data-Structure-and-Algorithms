/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

char* minRemoveToMakeValid(char * s){
        
    int size = strlen(s);
    int balance = 0;
    int pos = 0;
    
    char *result = (char*) malloc(size + 1 * sizeof(char));
    
    for(int i = 0; i < size; i++){
        if(isalpha(s[i])){
            result[pos++] = s[i];
            continue;
        }
        
        (s[i] == '(') ? ++balance : --balance;
        
        if(balance >= 0)
            result[pos++] = s[i];
        else
            balance = 0;
    }
    
    result[pos++] = '\0';
    
    int turn = 1;
    while(balance--){
        char ch = result[pos - turn];
        for(int i = pos - turn - 1; i >= 0; i--){
            char t = result[i];
            result[i] = ch;
            ch = t;
            
            if(ch == '(')
                break;
        }
        turn++;
    }
    
    return result;
}

/*
Note: remember the space declaration. and don't forget to insert null at the end.
case -  ()()(((
        here the null char of endOfString will be replaced with all extra opening braces.

    either you will remove closing para     (wherever mismatched)
        OR
    you will remove opening para            (from end of string)
*/
