/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/search-for-a-range/

int searchLeft(const vector<int>& A, int target, int i){
    int left = 0;
    int right = i;
    
    while(left < right){
        int mid = left + (right - left) / 2;
        if(A[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int searchRight(const vector<int>& A, int target, int i){
    int left = i;
    int right = A.size() - 1;
    
    while(left < right){
        int mid = left + (right - left) / 2;
        if(A[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return A[left] == target ? left : left - 1;
}

vector<int> Solution::searchRange(const vector<int> &A, int target){
    
    int foundAt = -1;
    int left = 0;
    int right = A.size();

    while(left < right){
        int mid = left + (right - left) / 2;
        if(A[mid] == target){
            foundAt = mid;
            break;
        }
        if(A[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }   
    
    if(foundAt != -1){
        int l = searchLeft(A, target, foundAt);
        int r = searchRight(A, target, foundAt);
        return {l ,r};
    }
    
    return {-1, -1};
}

/*
Search if the element exist in Array. (i)
If it does then search for Range else return -1;

Searching for range:
  search from 0 to i for left range
      if curr element is smaller than target, then search in right dir
      else search into left direction 
  search from i to size-1 for right range
      if curr element is greater then target, then search in left dir
      else search into right direction
*/
