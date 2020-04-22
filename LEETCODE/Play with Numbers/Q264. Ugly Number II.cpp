/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        
        int a = 2, b = 3, c = 5;
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i=1; i<n; ++i) {
            int last = ugly[i] = min(a, min(b, c));
            while(a <= last)
                a = 2 * ugly[++i2];
            while(b <= last) 
                b = 3 * ugly[++i3];
            while(c <= last) 
                c = 5 * ugly[++i5];
            
        }
        return ugly[n-1];
    }
};


/*                                    min of a,b,c (arr[i])
        2       3       5                   2    
        4       3       5                   3   
        4       6       5                   4
        6       6       5                   5
        6       6       10                  6
        8       9       10                  8
        10      9       10                  9
        10      12      10                  10
        
        and so on...
        basically its a table of multiplication with array values 
*/

