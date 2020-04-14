/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/multiply-strings/

void removeLeadingZeros(string& str){
    int i = 0;
    while(i < str.size() - 1 && str[i] == '0')
        i++;
    
    str = str.substr(i, str.length() - i);
}

string Solution::multiply(string num1, string num2){
    
    string curr = "";
    int two = num2.length() - 1;
    int putZeros = 0;
        
    while(two >= 0){
            
        int from = num2[two] - '0';
        int one = num1.length() - 1;
        int c = curr.length() - 1 - putZeros;
        int carry = 0;
            
        while(one >= 0){
            int oneMulTwo = num1[one] - '0';
            oneMulTwo *= from;
            oneMulTwo += carry;
                
            if(c >= 0)
                oneMulTwo += curr[c] - '0';
                
            char rem = oneMulTwo > 9 ? ('0' + (oneMulTwo % 10)) : ('0' + oneMulTwo);
            if(c >= 0)
                curr[c] = rem;  
            else
                curr = rem + curr;
                
                
            carry = oneMulTwo / 10;
            one--;
            c--;
        }

        if(carry != 0){
            if(c >= 0)
                carry += curr[c] - '0';
            
            char ch = '0' + carry;
            if(c >= 0)
                curr[c] = ch; 
            else
                curr = ch + curr;
        }                 
                        
        two--;
        putZeros++;
        //cout<<"\t"<<curr;
    }
        
    removeLeadingZeros(curr);
    return curr;
}

/*
Store the last digit of NUM2 in two

{ Multiply NUM2[two] with whole NUM1 (update into R) }
Decrement the two

// we Keep adding the multiplication of NUM[two] into (R) till two >= 0, while maintaining the zeros
}
*/

