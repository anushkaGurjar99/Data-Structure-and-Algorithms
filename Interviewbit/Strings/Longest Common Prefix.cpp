/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/longest-common-prefix/

string commonPrefix(string one, string two){
    string result = "";
    
    for(int i = 0; i < one.size() && i < two.size(); i++){
        if(one[i] == two[i])
            result += one[i];
        else
            break;
    }
    return result;
}


string Solution::longestCommonPrefix(vector<string> &A){
    if(A.size() < 1)
        return "";
        
    string result = A[0];
        
    for(int i = 1; i < A.size(); i++){
        result = commonPrefix(A[i], result);
        if(result == "")
            break;
    }
    return result;
}

/*
Assume the first String is our prefix.
Compare the assumend prefix with further string to get common prefix.
*/

