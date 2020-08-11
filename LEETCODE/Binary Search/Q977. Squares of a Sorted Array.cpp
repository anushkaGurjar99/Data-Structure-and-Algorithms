/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution{
public:
    vector<int> sortedSquares(vector<int>& A){
        
        int l = getMinPositive(A);
        int r = l + 1;
        int size = A.size();
        vector<int> result(size);
        
        for(int i = 0; i < size; i++){
            int value = 0;
            if(l >= 0 && r < size){
                bool b = (A[l] * A[l] <= A[r] * A[r]);
                value = (b) ? getNumber(A[l], l, -1) : getNumber(A[r], r, 1);
            }
            else{
                value = (l >= 0) ? getNumber(A[l], l, -1) : getNumber(A[r], r, 1);
            }            
            result[i] = value;
        }
        
        return result;
    }
    
    int getNumber(int& num, int& pos, int val){
        pos += val;
        return num * num;
    }
    
    int getMinPositive(vector<int>& A){
        int l = 0;
        int r = A.size() - 1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(A[mid] == 0)
                return mid;
            
            if(A[mid] < 0)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return l - 1;
    }
};


/*
Approach:
    since the array is sorted and have -ve in it
    so we find the index which contains either 0 or -ve value (Log n time)
    
    compare square of both left and right position     
    store the smaller square at current pos and update the index
    
    if any of the index is out of range then keep store from second end.
*/


