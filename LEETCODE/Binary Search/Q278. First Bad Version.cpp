/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/first-bad-version/

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

// we want the first bad version which is the leftest bad version.
