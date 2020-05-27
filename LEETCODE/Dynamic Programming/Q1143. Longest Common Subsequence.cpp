/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/longest-common-subsequence/

class Solution{
public:
    int longestCommonSubsequence(string text1, string text2){
        
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++){
                
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
            }
        }
        
        return dp[text1.size()][text2.size()];
    }
};

/*
lets consider i is the index to traverse the text1 string.
j is the index to traverse the the tex2 string.

we should divide our problem into sub problems:
    text[i] == text[j]
    text[i] != text[j]
*/
