/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/climbing-stairs/

class Solution{
public:
    int climbStairs(int n){
        
        if(n <= 3)
            return n;
        
        int limit = n - 2;
        int first = 1;
        int second = 2;
        int result;
        
        while(limit-- > 0){
            result = first + second;
            first = second;
            second = result;
        }
        
        return result;
    }
};

/*
For each cell we have two ways to reach out:
    1. By jumping from prev Stair
    2. By jumping from prev to prev Stair

So we can sum up 1 and 2 for each cell (to count how many ways are there to reach)

Initliaze:  first cell with 1 
            second cell with 2 
            (to make further calls)
*/
