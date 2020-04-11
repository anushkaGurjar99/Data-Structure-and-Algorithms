/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/count-and-say/

#include<stdio.h>

string getNextSequence(string s){
    string next = "";
        
    for(int i = 0; i < s.size(); i++){
        int count = 1;
        char ch = s[i];
        while(s[i] == s[i+1]){
            i++;
            count++;
        }
        next.push_back(count + '0');
        next.push_back(ch);
    }
        
    return next;
}
    
string Solution::countAndSay(int n){
    string sequence = "1";                              // we know the first sequence
    while(n > 1){
        string temp = getNextSequence(sequence);
        //cout<<"\n"<<temp;
        sequence = temp;
        n--;
    }
    return sequence;
}


/*
Approach:
    each "same subsequence/ frequency" need two things: 1. COUNT      2. CHARACTER
    
    Generate the next subsequence based on 1 and 2 and store for next iteration (say in N)
    Then in next iteration process the N
    
    follow above two steps till (n > 1), skip first sequence as we alreay know it.
*/

