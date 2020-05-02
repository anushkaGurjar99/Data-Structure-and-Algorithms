/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n){
        
        int left = 1;
        int right = n;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};

// Binary Search
