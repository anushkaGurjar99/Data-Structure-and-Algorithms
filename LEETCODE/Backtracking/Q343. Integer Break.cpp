/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/integer-break/

class Solution{
public:
    int integerBreak(int n){
        int result = 0;
        backtrack(n, result, 1 , 0, 1);                // input, result, product, sumOfnums, start
        return result;
    }
    
    void backtrack(int input, int& result, int product, int sumOfnums, int start){
        if(sumOfnums == input){
            result = max(result, product);
            return;
        }
        
        for(int i = start; i < input; i++){
            if(sumOfnums + i <= input)
                backtrack(input, result, product * i, sumOfnums + i, i);
            else
                break;
        }
    }
};

/*
Solution 1: Backtracking
    
    n = 10
    
    1 1 1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1 2
    1 1 1 1 1 1 1 2 1
    1 1 1 1 1 1 2 2
    ....
    3 3 3 1
    3 3 4
    ...and so on
*/


