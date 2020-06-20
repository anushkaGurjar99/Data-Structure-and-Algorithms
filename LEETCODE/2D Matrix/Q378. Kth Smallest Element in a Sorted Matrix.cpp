/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k){
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n - 1][n - 1];
        
        while(start < end){
            int mid = start + (end - start) / 2;
            
            pair<int, int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};       // init
            
            int count = countLessEqual(matrix, mid, smallLargePair);
            if(count == k)
                return smallLargePair.first;

            if(count < k)
                start = smallLargePair.second;      // Search higher
            else
                end = smallLargePair.first;         // Search lower
        }
        
        return start;
    }

    int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair){
        int count = 0;
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        
        while(row >= 0 && col < n){
            if(matrix[row][col] > mid){             
                smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
                row--;
            }
            else{
                smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
                count += row + 1;
                col++;
            }
        }
        return count;
    }
};

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/301357/Java-0ms-(added-Python-and-C%2B%2B)%3A-Easy-to-understand-solutions-using-Heap-and-Binary-Search

/*
countLessEqual:
    while loop:
        get the just greater than mid
        get the just smaller than mid (keep count of just smallers)
        
Now check if count matches to K
    If it does return the 'just greater'
    Else keep searcheing for the exact Count.
        if count was higher -> search Left
        else -> search Right
*/

// *************************************************** Using PQ ***********************************************************

class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto row: matrix){
            for(auto num: row)
                pq.push(num);
        }
        
        while(k-- > 1)
            pq.pop();
        
        return pq.top();
    }
};

