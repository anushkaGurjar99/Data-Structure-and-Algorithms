/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution{
public:
    int longestPalindromeSubseq(string s){
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int len = 1; len < n; len++){
            for(int i = 0; i + len < n; i++){
                int j = i + len;
                
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                
                //cout<<"  "<<i<<":"<<j<<" "<<dp[i][j];
            }
            //cout<<"\n";
        }
        
        return dp[0][n - 1];
    }
};

/*
Sub Problems: - 
        1). If both char matched
            2 + longest palindrome between both char (obtained from bottom left diognal)
        2). If char does not matched
            maximum of left or bottom cell
           
Each [i][j] represents LPS from the ith char to jth char of string.
    
    EX.: "aaxyaa"
    
    Initial filling (we know that each individual char is a palindrome)
    
        a   a   x   y   a   a
    a   1
    a       1
    x           1
    y               1
    a                   1
    a                       1
    
    
        a   a   x   y   a   a                   a   a   x   y   a   a
    a   1   2                               a   1   2   2
    a       1   1                           a       1   1   1
    x           1   1                       x           1   1   1
    y               1   1                   y               1   1   1
    a                   1   2               a                   1   2
    a                       1               a                       1
    
    
        a   a   x   y   a   a                   a   a   x   y   a   a
    a   1   2   2   2                       a   1   2   2   2   3  [5]
    a       1   1   1   3                   a       1   1   1   3   3
    x           1   1   1   1               x           1   1   1   1
    y               1   1   1               y               1   1   1
    a                   1   2               a                   1   2
    a                       1               a                       1
    
    Return Last cell of first row;
*/

