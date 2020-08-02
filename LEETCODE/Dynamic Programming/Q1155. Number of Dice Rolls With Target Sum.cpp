/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution{
public:
    int numRollsToTarget(int d, int f, int target){
        
        vector<vector<int>> dp(d, vector<int> (target + 1, 0));
        
        for(int i = 1; i <= target && i <= f; i++)
            dp[0][i] = 1;
        
        for(int r = 1; r < d; r++){
            long long sum = 0;
            
            for(int c = 1; c <= target; c++){
                dp[r][c] = sum % 1000000007;
                
                sum += dp[r - 1][c];
                
                if(c > f)
                    sum -= dp[r - 1][c - f];
            }
        }
            
        return dp[d - 1][target];
    }
};

/*
    youtube.com/watch?v=UiYVToWORMY
    
    ROWS are target
    COLS are number of dice
*/

