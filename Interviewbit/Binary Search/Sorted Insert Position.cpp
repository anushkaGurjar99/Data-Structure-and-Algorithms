/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B){
    
    if(A.size() < 1)
        return 0;
    
    int left = 0;
    int right = A.size();
    
    while(left < right){
        int mid = left + (right - left) / 2;
        if(A[mid] == B){
            left = mid;
            break;
        }
        
        if(A[mid] < B)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;
}

/*
Search the target value into array
  if found -> reurn that index
  else -> return last scanned position
*/
