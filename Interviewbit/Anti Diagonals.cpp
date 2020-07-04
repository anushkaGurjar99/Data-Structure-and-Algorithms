/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/anti-diagonals/

vector<int> findAntiDiagonals(vector<vector<int>> &A, int r, int c){
    vector<int> ad;
    while(r < A.size() && c >= 0){
        ad.push_back(A[r][c]);
        r++, c--;
    }
    return ad;
}

vector<vector<int> > Solution::diagonal(vector<vector<int>> &A){
    
    vector<vector<int>> result;
    vector<int> temp;
    
    for(int col = 0; col < A[0].size(); col++){
        temp = findAntiDiagonals(A, 0, col);
        result.push_back(temp);
    }
    
    for(int row = 1; row < A.size(); row++){
        temp = findAntiDiagonals(A, row, A[0].size() - 1);
        result.push_back(temp);
    }
    
    return result;
}

/*
    Traverse the Top row
    Traverse the Right col
*/
