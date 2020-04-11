/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/power-of-2/

#include<stdio.h>

#include<stdio.h>

int Solution::power(string A){
    
    if(A == "")
        return 0;
    
    short result = 1;
    
    while(1){
        
        int i = 0;
        short rem = 0;
        short num = 0;
        string temp = "";
        
        short last = A.back() - '0';
        
        if(last % 2 != 0){                              // If last digit odd (break)
            result = 0;
            break;
        }
        
        // cutting the number into half
        while(i < A.length()){                          
            
            num *= 10;                                  // carry case
            num += A[i] - '0';    
            if(num < 2 && i+1 < A.size()){              // if A[i] is either 0 or 1
                if(i != 0)
                    temp.push_back('0');
                i++;
                num *= 10;
                num += A[i] - '0';
            }
            rem = num % 2;
            num /= 2;
            temp.push_back(num + '0');   
            i++;
            num = (rem == 0) ? 0 : rem;
        }
        
        if(temp.length() == 1 && temp[0] == '1')                    // answer found
            break;       
        A = temp; 
    }    
    return result;
}


/*
Approach:
Get the half of number till either 1 or some odd number is found;
Odd number means it is not power of two whereas 1 means the number is power of 2.
*/
