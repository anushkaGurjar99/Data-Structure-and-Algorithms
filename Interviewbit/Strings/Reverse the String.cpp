/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/reverse-the-string/

void insertWord(string& result, string& word){
    if(word != ""){
        result = (result == "") ? word : word + ' ' + result;
        word = "";
    }
}

string Solution::solve(string s){

    string result = "";
    string word = "";
    
    for(int i = 0; i < s.length(); i++){
        
        if(s[i] == ' '){
            insertWord(result, word);
            while(i < s.size() && s[i+1] == ' ')              
                i++; 
        }   
        else{
            word += s[i];
        }
    }
    insertWord(result, word);
    
    return result;
}
    
