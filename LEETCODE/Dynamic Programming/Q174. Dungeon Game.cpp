/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector dp(rows, vector<int>(cols, 0));
        
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                
                if(i == rows - 1 && j == cols - 1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                
                else if(i == rows - 1)
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                
                else if(j == cols - 1)
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
        
                else
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
    
        return dp[0][0];
    }
};

// ********************************************************************************************************************
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        int rows = dungeon.size();
		int cols = dungeon[0].size();
		vector<vector<int>> dp(rows + 1, vector<int> (cols + 1));

		for(int i = 0; i <= rows; i++)
			dp[i][cols] = INT_MAX;
	
		for(int j = 0; j <= cols; j++)
			dp[rows][j] = INT_MAX;
	
		dp[rows][cols - 1] = 0;
		dp[rows - 1][cols] = 0;
		
        for(int i = rows - 1; i >= 0; i--){
		    for(int j = cols - 1; j >= 0; j--)
				dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 0);
		}

		return dp[0][0] + 1;
    }
};

// https://leetcode.com/problems/dungeon-game/discuss/52826/A-very-clean-and-intuitive-solution-(with-explanation)
