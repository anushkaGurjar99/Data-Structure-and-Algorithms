/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/fibonacci-number/

class Solution{
public:
    int fib(int N){
        if(N == 0)
            return 0;
        else if(N == 1)
            return 1;
        
        return getFibo(N, 0, 1);
    }
    
    int getFibo(int limit, int secLast, int last){
        if(limit >= 2)
            return getFibo(limit - 1, last, secLast + last);
        return last;
    }
};

/*
Base case:
  return last calculated element when target is reached.
*/


// ******************************************************* More elegant ****************************************************************

class Solution{
public:
    int fib(int N){
        if(N <= 1)
            return N;
        
        return fib(N - 1) + fib(N - 2);
    }
};

/*
    Base case:
        N = 0, return 0
        N = 1, return 1
 
If not base case then return sum of prev 2 elements till base case reached.
*/
