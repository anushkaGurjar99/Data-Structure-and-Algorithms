/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/intersection-of-sorted-arrays

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B){
    vector<int> result;
    
    if(A.size() == 0 || B.size() == 0)
        return result;
    
    int one = 0;
    int two = 0;
    
    while(one < A.size() && two < B.size()){
        if(A[one] == B[two]){
            result.push_back(A[one]);
            ++one , ++two;
        }
        else{
            (A[one] < B[two]) ? ++one : ++two;
        }
    }
    
    return result;
}

/*
Take two pointers pointing to both arrays(say ONE and TWO)
WHILE ONE AND TWO POINTING TO VALID INDEX
  If ONE and TWO indexes have same value then store the value.
  else
    if ONE is less than TWO
      move ONE one step ahead
    else
      move TWO one step ahead
*/
