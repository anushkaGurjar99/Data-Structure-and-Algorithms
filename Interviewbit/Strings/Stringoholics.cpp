/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/stringoholics/

#include<stdio.h>

bool rotateAllStrings(vector<string> &A, vector<string> original, int& rotation){
    
    for(int i = 0; i < A.size(); i++){
        string word = A[i];
        int size = word.size();
        int r = rotation % size;
        string save = word;
        word = save.substr(r, size - r);
        word += save.substr(0, r);
        A[i] = word;
    }
    
    return (original == A) ? true : false;
}

int Solution::solve(vector<string> &A){
    
    int count = 0;
    int rotation = 1;
    vector<string> original = A;
    
    while(rotateAllStrings(A, original, rotation) == false)
        rotation++;
    
    return rotation - 1;
}
