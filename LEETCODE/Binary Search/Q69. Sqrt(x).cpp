/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x){
        
        long left = 0;
        long right = x;
        long mid = 0;
        
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(mid * mid == x){
                left = mid;
                break;
            }
            
            if(mid * mid < x)
                left = mid + 1;
            else
                right = mid;
        }
        
        return (left * left == x) ? left : left - 1;
    }
};
/*
Binary Search
    search left if square is greater than x
    else search right
    break if result found
*/


// ***************************************************************************************************************

class Solution {
public:
    int mySqrt(int x){
        
        long int sqrt = 0;
        long int i = 0;
        
        while(x > sqrt){
            i++;
            sqrt = i * i;
        }
        
        return (x == sqrt) ? i : i - 1;
    }
};

/*
Keep calculating sqrt till just greater or equal num is found.
*/
