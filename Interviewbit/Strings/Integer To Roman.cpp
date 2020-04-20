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
