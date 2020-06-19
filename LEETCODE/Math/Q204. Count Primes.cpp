/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n){
        
        if(n <= 2)
            return 0;
        
        vector<bool> prime(n, true);
        
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 0; i < sqrt(n); i++){
            if(prime[i]){
                for(int j = i * i; j < n; j += i)
                    prime[j] = false; 
            }
        }
        
        return count(prime.begin(), prime.end(), true);
    }
};

// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
