/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/uncrossed-lines/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B){
        
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
              
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++){

                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            
            }
        }
        return dp[A.size()][B.size()];
    }    
};

/*
dp[i][j] denote the LCS between the first i elements of A and the first j elements of B
Similar Ques:
LCS, Edit Distance, Max dot product of 2 subsequence
*/


/************************************************* TLE backtracking solution /************************************************

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B){
        
        if(A.size() < 1 || B.size() < 1)
            return 0;
        
        int result = 0;
        backtrack(A, B, result, -1, 0, 0);
        return result;
    }
    
    void backtrack(vector<int>& A, vector<int>& B, int& result, int lastVisited, int match, int index){
        
        result = max(result, match);

        if(index == A.size() || lastVisited + 1 == B.size())
            return;
                
        for(int i = index; i < A.size(); i++){
            for(int j = lastVisited + 1; j < B.size(); j++){
                if(A[i] == B[j]){
                    int save = B[j];
                    B[j] = 0;
                    backtrack(A, B, result, j, match + 1, i + 1);
                    B[j] = save;
                }
            }
        }
    }
};

