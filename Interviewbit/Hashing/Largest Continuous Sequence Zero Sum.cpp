/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum

vector<int> Solution::lszero(vector<int> &A){
    
    unordered_map<int, int> m;
    vector<int> result;
    int currLen = 0;
    int cf = 0;
    
    m.insert({0,-1});                               // if our longest sequence is starting from 0th index
    
    for(int i = 0; i < A.size(); i++){
        
        cf += A[i];
        auto itr = m.find(cf);
        
        if(itr != m.end()){
            currLen = max(currLen, i - itr->second);
            if(result.size() < currLen){
                vector<int> temp(A.begin() + itr->second + 1, A.begin() + i + 1);
                result = temp;
            }
        }
        else{
             m.insert({cf, i});
        }
        
    }    
    return result;
}


/*
Intuition:
(CF of an element is the sum of its predecessors. If at any point we got the repeated CF, means that there is 0Sum in between both CF)
For example : array     1   2   3   -4  -1   8
              CF    0   (1) 3   6    2  (1)  9            
              
Approach:
    Keep calculating the CF
    If we found the CF already exist in map 
        (then calculate the number of elements pos_of_CF1 + 1 to pos_of_CF2 in CURRLEN)
        (if CURRLEN then result length which was 0 initially, then overwrite the result)
    else
      store CF into map
      
return the result
*/
