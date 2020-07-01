/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n){
        
        if(n <= 1)
            return n;
        
        long limit = 1;
        long right = 1;
        
        while(limit < n){
            right *= 2;
            limit = right * (right + 1) / 2;
        }
        
        if(limit == n)
            return right;
        
        long left = right / 2;
               
        while(left < right){
            long mid = left + (right - left) / 2;
            limit = mid * (mid + 1) / 2;
            
            if(limit <= n)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left - 1;
    }
};

/*
    A simple Binary Search between right and left range.
*/

