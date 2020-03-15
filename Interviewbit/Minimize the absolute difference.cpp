/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/minimize-the-absolute-difference

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int i = A.size() - 1;
    int j = B.size() - 1;
    int k = C.size() - 1;
    
    int minn = INT_MAX;
    
    while(i != -1 && j != -1 && k != -1){                                         // if any of array goes out of bound, we have to terminate as we have already found the RESULT and no need to traverse other two arrays
        int cur = max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k]));
        
        if(cur < minn)
            minn = cur;
        
        int maxx = max(A[i], max(B[j], C[k]));
        
        if(maxx == A[i])
            i--;
        else if(maxx == B[j])
            j--;
        else
            k--;
    }
    return minn;
}
