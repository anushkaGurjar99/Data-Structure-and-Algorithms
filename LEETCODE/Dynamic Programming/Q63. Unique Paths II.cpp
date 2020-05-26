/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/unique-paths-ii/

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        
        if(obstacleGrid.size() == 0 || obstacleGrid[0][0] == 1)
            return 0;
        
        vector<int> path(obstacleGrid[0].size(), 1);
        
        for(int j = 1; j < path.size(); j++)
            path[j] = (obstacleGrid[0][j] == 1) ? 0 : path[j - 1];
        
        for(int i = 1; i < obstacleGrid.size(); i++)
            getUniquePathOfCurrentRow(obstacleGrid[i], path);
        
        return path[path.size() - 1];
    }
    
    void getUniquePathOfCurrentRow(vector<int>& obstacle, vector<int>& path){
        path[0] = (obstacle[0] == 1) ? 0: path[0];
        
        for(int i = 1; i < path.size(); i++)
            path[i] = (obstacle[i] == 1) ? 0: path[i - 1] + path[i];
    }
};

/*
If first cell is an obstacle we can't find the path anyway.

Set first Row
Find path for remaining rows (*)

*
same as 'unique path',  just remember if any Obstacle found
                        we can never get to that cell, so mark that cell 0
*/
