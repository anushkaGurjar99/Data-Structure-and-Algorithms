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
        
        int c2 = 2, c3 = 3, c5 = 5;
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i=1; i<n; ++i) {
            int last = ugly[i] = min(c2, min(c3, c5));
            while(c2 <= last)
                c2 = 2 * ugly[++i2];
            while(c3 <= last) 
                c3 = 3 * ugly[++i3];
            while(c5 <= last) 
                c5 = 5 * ugly[++i5];
            
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

