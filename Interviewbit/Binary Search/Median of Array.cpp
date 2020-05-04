/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B){
    
    if(A.size() > B.size())
        return findMedianSortedArrays(B, A);

    int x = A.size();
    int y = B.size();
        
    int low = 0;
    int high = x;
        
    while(low <= high){
        int xpartition = (low + high)/2;
        int ypartition = (x + y + 1) / 2 - xpartition;
        
        int maxleftx  = (xpartition == 0) ? INT_MIN: A[xpartition-1];
        int maxlefty  = (ypartition == 0)?  INT_MIN: B[ypartition-1];
        int minrightx = (xpartition == x) ? INT_MAX: A[xpartition];
        int minrighty = (ypartition == y)?INT_MAX : B[ypartition];
             
        if(maxleftx <= minrighty && maxlefty <= minrightx){
            double left = double(max(maxleftx, maxlefty));
            double right = double(min(minrightx, minrighty));
            if((x + y) % 2 == 0) 
               return (left + right) / 2;
            return left;    
        }
        
        if(maxleftx > minrighty)        // move left
            high = xpartition - 1;
        else                            // move right
            low = xpartition + 1; 
    }
    return 0;
}

// https://www.youtube.com/watch?v=LPFhl65R7ww&t=1131s
/*

    we are applying BS on array A so size of array A must be < or = to array B
    Time C: O(log(min(M,N))
    
    partition both array and check the corner points
    if valid corners -> return the result
    else shift the separators
*/
