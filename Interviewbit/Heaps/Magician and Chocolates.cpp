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
        
    while(limit > 0){
        int top = pq.top();
        pq.pop();
        if(top == 0)
            break;
        result += top;
        top /= 2;
        pq.push(top);
        limit--;
        result %= mod;
    }
    return result;
}

// to use mod: result %= static_cast<long>(pow(10,9) + 7);
