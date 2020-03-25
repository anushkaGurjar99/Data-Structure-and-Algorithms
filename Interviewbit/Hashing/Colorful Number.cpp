/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/colorful-number/

int Solution::colorful(int A){
    
    unordered_multiset<int> unique;
    
    string digits = to_string(A);
    
    for(int range = 1; range <= digits.size(); range++){
        for(int j = 0; j < digits.size() && (j + range) <= digits.size();){
            
            int mul = 1;
            int size = range;
            while(size > 0){
                mul *= (digits[j] - '0');
                j++;
                size--;
            }
            
            if(unique.find(mul) == unique.end())
                unique.insert(mul);
            else
                return false;
        }
    }    
    return true;
}
