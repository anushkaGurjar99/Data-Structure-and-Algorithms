/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/fraction


string Solution::fractionToDecimal(int numerator, int denominator) {
    if(!numerator)
        return "0";
    
    string ans;
    if(numerator > 0 ^ denominator > 0)
        ans += '-';
    
    long n = labs(numerator);
    long d = labs(denominator);
    long rem = n % d;
    
    ans += to_string(n / d);
    
    if(!rem) 
        return ans;
        
    ans += '.';
    unordered_map<long, int> m;
    
    while(rem){
        if(m.find(rem) != m.end()){
            ans.insert(m[rem], "(");
            ans += ')';
            break;
        }
        m[rem] = ans.size();
        rem *= 10;
        ans += to_string(rem / d);
        rem %= d;
    }
    return ans;
}
