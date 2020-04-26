/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/n-max-pair-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B){
    
    priority_queue<int, vector<int>, greater<int> >min_heap;
    
    sort(A.begin(),A.end(),greater<int> ());
    sort(B.begin(),B.end(),greater<int> ());
    
    int n = A.size();
    
    for(int i = 0; i < n; i++)
        min_heap.push(INT_MIN + i);

    bool flag = false;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i] + B[j] > min_heap.top()){
                min_heap.pop();
                min_heap.push(A[i] + B[j]);
                flag = true;
            }
            else
                break;
        }
        if(!flag) 
            break;
    }
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        ans[i] = min_heap.top();
        min_heap.pop();
    }
    return ans;
}
