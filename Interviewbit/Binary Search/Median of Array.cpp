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
        int midX = (low + high)/2;
        int midY = (x + y + 1) / 2 - midX;
        
        int maxLeftX  = (midX == 0) ? INT_MIN : A[midX - 1];
        int maxLeftY  = (midY == 0) ? INT_MIN : B[midY - 1];
        int minRightX = (midX == x) ? INT_MAX : A[midX];
        int minRightY = (midY == y) ? INT_MAX : B[midY];
             
        if(maxLeftX <= minRightY && maxLeftY <= minRightX){
            double left = double(max(maxLeftX, maxLeftY));
            double right = double(min(minRightX, minRightY));
            if((x + y) % 2 == 0) 
               return (left + right) / 2;
            return left;    
        }
        
        if(maxLeftX > minRightY)        // move left (Array1)
            high = midX - 1;
        else                            // move right (Array1)
            low = midX + 1; 
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
