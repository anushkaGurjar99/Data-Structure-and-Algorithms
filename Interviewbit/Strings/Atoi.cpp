/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/atoi/


int Solution::atoi(const string str){
    
    int i = 0;
    long int result = 0;
    char sign = '+';
    
    while(str[i] == ' ')                                    // Remove the whiteSpace 
        i++;
        
        
    if(str[i] == '-' || str[i] == '+'){                     // If sign then get first chat with -+
        sign = str[i];
        i++;
            
        if(str[i] >= '0' && str[i] <= '9'){
            result = str[i] - '0';
            result *= (sign == '-') ? -1 : 1;
            i++;
        }
        else{
            return result;
        }
    }
        
        
    // Get the remaining sequence
        
    while(str[i] >= '0' && str[i] <= '9'){
        result *= 10;
            
        result = (sign == '-') ? result - (str[i]-'0') : result + (str[i]-'0');
        
        if(result > INT_MAX){
            result = INT_MAX;
            break;
        }
            
        else if(result < INT_MIN){
            result = INT_MIN;
            break;
        }
        i++;
    }
    
    return result;
}

/*
Process Follows the following Steps :       
1. Remove the whiteSpace                                        while Loop
2. Get the Sign and first char (if sign exist)                  If cond
3. get the remaining sequence                                   while loop
*/



/*
SET OF QUESTIONS THAT CAN BE ASKED....

Q1. Does string contain whitespace characters before the number?
A. Yes 

Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. 

Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. 

Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
*/
