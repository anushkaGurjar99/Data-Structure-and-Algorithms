/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num){
        for(int i = 2; i <= 5 && num; i++){
            while(num % i == 0)
                num /= i;
        }
        return (num == 1);
    }
};
