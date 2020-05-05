/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement:https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A){
    
    long left = 0;
    long right = A;
    long mid = 0;
        
    while(left < right){
        mid = left + (right - left) / 2;
        
        if(mid * mid == A){
            left = mid;
            break;
        }
        
        if(mid * mid < A)
            left = mid + 1;
        else
            right = mid;    
    }
    return (left * left == A) ? left : left - 1;
}

/*
Binary Search
    search left if square is greater than x
    else search right
    break if result found
*/
