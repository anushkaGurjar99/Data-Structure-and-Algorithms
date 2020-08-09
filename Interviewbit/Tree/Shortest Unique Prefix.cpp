/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/shortest-unique-prefix/

vector<string> Solution::prefix(vector<string> &A){
    
    unordered_multiset<string> ms;
    
    for(int i = 0; i < A.size(); i++){
        string s;
        for(int j = 0; j < A[i].size(); j++){
            s.push_back(A[i][j]);
            ms.insert(s);
        }
    }
    
    vector<string> result;
    
    for(int i = 0; i < A.size(); i++){
        string s;
        for(int j = 0; j < A[i].size(); j++){
            s.push_back(A[i][j]);
            if(ms.count(s) == 1){
                result.push_back(s);
                break;
            }
        }
    }
    
    return result;
}

/*
    App1: using MS
    App2: using Trie
*/
