/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B){

    string result;
    int i = A.size();
    int j = B.size();
    int carry = 0;
        
    while(i > 0 || j > 0 || carry == 1){
        
        int sum =   ((i > 0) ? A[--i] - '0' : 0) + 
                    ((j > 0) ? B[--j] - '0' : 0) + 
                    carry;
            
        if(sum == 1 || sum == 3)
            result.push_back('1');
        else
            result.push_back('0');
            
        carry = sum < 2 ? 0 : 1; 
    }
    reverse(result.begin(), result.end());
    
    return result;
}

/*
(sum == 1 || sum == 3) means sumToBeInserted = 1.

and if (sum == 0 || sum == 2) mean sumToBeInserted = 0.
    for carry if (sum < 2) then carry = 0 else carry = 1.
*/
