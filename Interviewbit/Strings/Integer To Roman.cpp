/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int num){
    string result;
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    for(int i=0; num != 0; i++){
        while(num >= val[i]){
            num -= val[i];
            result += roman[i];
        }
    }
    
    return result;
}

// ************************************************ Another approach ************************************************

string Solution::intToRoman(int num){
    unordered_map<int, string> m;
    m[1] = "I";
    m[5] = "V";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
        
    string result = "";
        
    int zeros = 1;
    int start = 1;
    int end = 5;
        
    while(num != 0){
    int curr = num % 10;
        string roman = "";
        
        if(curr == 9){
            roman = m[start] + m[start * 10];
        }
        else if(curr == 4){
            roman = m[start] + m[end];
        }
        else{
            curr *= zeros;
            while(curr > 0){
                if(curr < end){
                    roman += m[start];
                    curr -= start;
                }
                else{
                    roman += m[end];
                    curr -= end;
                }
            }
        }   
        result = roman + result;
        start *= 10, end *= 10, zeros *= 10;
        num /= 10;
    }   
    return result;
}


/*
Approach:
    Convert the number from back
    
    for ex: if the number is 2571
            the we have to generate roman of 1, 70, 500, 2000 then merge the sequence
    
    'start' and 'end' denoting the roman number available for particular number
    say for 63 we have the start = X and end = L
    
    if it is special case -> encode directly
    else convert accordingly
    
    each time we update 'number of zeros', 'start', 'end'
*/


// short trick
// https://leetcode.com/problems/integer-to-roman/discuss/6489/Sharing-my-really-simple-solution-with-explanation
