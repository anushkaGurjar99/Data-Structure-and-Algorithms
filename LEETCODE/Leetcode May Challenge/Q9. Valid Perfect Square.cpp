/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num){
        int i = 1;
        
        while(num > 0){
            num -= i;
            i += 2;
        }
        
        return num == 0;
    }
};

/*
  This solution makes use of the fact that all square numbers are sum of odd numbers starting from 1.
  For ex:
  1 = 1
  1+3 = 4
  1 + 3 + 5 = 9
  1 + 3 + 5 + 7 = 16
  .... and so on
  So Keep subtracting odd numbers from the given number, starting from 1. 
  If the number eventually reaches 0, it is a perfect square. 
  If it reaches a negative number without reaching 0 it is not a perfect square.
*/

// *****************************************************************************************************************

class Solution {
public:
    bool isPerfectSquare(int num){
        long i = 1;
        long sq = 1;
        
        while(sq < num){
            i++;
            sq = i * i;
        }
        
        return sq == num;
    }
};
