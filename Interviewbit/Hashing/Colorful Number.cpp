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
    
    vector<int> digits;
    while(A > 0){
        digits.insert(digits.begin(), A % 10);
        if(unique.find(A % 10) == unique.end())
            unique.insert(A % 10);
        else
            return false;
        A = A/10;
    }
    
    for(int range = 2; range <= digits.size(); range++){
        for(int j = 0; j < digits.size() && (j + range) <= digits.size();){
            
            int mul = 1;
            int size = range;
            while(size > 0){
                mul *= digits[j];
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
