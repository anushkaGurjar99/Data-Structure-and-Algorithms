/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A){
    vector<int> res(A.size(),-1);
    stack<int> nums;
    for(int i = A.size()-1; i >= 0; i--){
        if(nums.empty() || A[nums.top()] <= A[i]){
            nums.push(i);
        }
        else{
            while(A[nums.top()] > A[i]){
                res[nums.top()] = A[i];
                nums.pop();
                if(nums.empty())
                    break;
            }
            nums.push(i);
        }
    }
    return res;
}
