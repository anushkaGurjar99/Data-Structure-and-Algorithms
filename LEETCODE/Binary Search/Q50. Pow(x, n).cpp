/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/powx-n/

class Solution{
public:
    double myPow(double x, int n){
        
        if(n == 0) return 1;
        if(x == 1) return 1;
        
        unordered_map<long, double> m;
        m[1] = x;
            
        double result = x;
        long start = 1;
        int limit = abs(n);
        int sign = (x > 0) ? 1 : (n % 2 == 0) ? 1 : -1;
        
        while(start < limit){
            start *= 2;
            result *= result;
            m[start] = result;
        }
        
        result = abs(m[start]);
        
        if(start != limit)
            result = helper(m, start, start / 2, limit);
        
        return (n < 0) ? 1/result : sign * result;
    }
    
    double helper(unordered_map<long, double>& m, int r, int l, int limit){
        while(l < r){
            int mid = l + (r - l) / 2;
            m[mid] = m[l] * m[mid - l];

            if(mid == limit)
                l = r = mid;
            else if(mid > limit)
                r = mid;
            else
                l = mid;
        }
        
        return abs(m[l]);
    }
};

/*
Approach: 
    Keep doubling the start(which is initailly 1) till it is smaller than target-power
    and store the answer into map.
        start: 1, 2, 4, 8, 16, 32, 64 .... limit
        
    After the loop we will be able to access m[1], m[2], m[4], m[8], m[16], m[32] ..... m[limit]
        
    if limit == start
        we can simply return the m[start]
    else 
        we will apply binary search.
        
How would you apply binary search ?
    right bound will be start (we know that start is > limit so target-power must be < right)
    left bound will be start/2 (we know that start/2 was < limit so target-power must be > left)

    Since we have already stored base powers into Map, we can access two power to calculate new one
    For ex:
        target-power = 6, number = 2
        
        left = 4
        right = 8
        
        mid = 4 + (8 - 4) / 2 => 6
        mid is nothing but multiplication of m[left] and m[mid - left]
                                                m[4] * m[2]
    
    If mid is < target-power then our left bound will be updated else right bound will be updated.
    We keep doing this till (mid == target power)


Now comes the sign calculation -
    1. Any +ve number will always generate +ve result.
    1. Any -ve target-power will result in division by 1 of final answer
    2. Any -ve number having the even power results in +ve answer 
*/
