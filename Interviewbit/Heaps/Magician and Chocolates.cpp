/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int limit, vector<int> &chocolates){
    priority_queue<int> pq;
    long result = 0;
    long mod = 1000000007;
    for(auto i: chocolates)
        pq.push(i);
        
    while(limit-- > 0){
        int top = pq.top();
        pq.pop();
        result += top;
        pq.push(top / 2);
        result %= mod;
    }
    return result;
}

// to use mod: result %= static_cast<long>(pow(10,9) + 7);
// as mentioned in question that top will be greater than or equal to 1, we don't need to check that is top == 0
