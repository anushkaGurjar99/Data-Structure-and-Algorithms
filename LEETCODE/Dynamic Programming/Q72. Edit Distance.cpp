/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2){
        
        int rows = word1.size();
        int cols = word2.size();
        
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        
        // base case
        for(int i = 0; i <= rows; i++)
            dp[i][0] = i;
        
        for(int j = 0; j <= cols; j++)
            dp[0][j] = j;
        
        // *
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
        
        return dp[rows][cols];
    }
};
