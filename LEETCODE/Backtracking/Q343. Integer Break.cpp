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


// **************************************************************** Approach 2 ******************************************************************************
class Solution{
public:
    int integerBreak(int n){
        
        if(n <= 3)
            return (n - 1);
        
        int result = 0;
        dfs(n, 1, result, 1, 0);
        return result;
        
    }
    
    void dfs(int num, int product, int& result, int start, int count){
        if(num == 0){
            result = max(result, product);
            return;
        }
        
        for(int i = start; num - i >= 0; i++)
            dfs(num - i, product * i, result, i, count + 1);
    }
};

/*
    Just to make sure we check two elements at least ->
        we check the edge case
        
    Then we divide a number till it gets 0 and try all combinations because we know number > 3 must have
    a combination which is greater than or equals to given input n;
*/
