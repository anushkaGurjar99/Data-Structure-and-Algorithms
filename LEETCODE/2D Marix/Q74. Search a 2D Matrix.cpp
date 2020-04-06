/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        int targetRow = -1;
        
        int r;
        for(r = 0; r < matrix.size(); r++){
            if(matrix[r][0] <= target)
                targetRow = r;
            else
                break;
        }
        
        return  targetRow == -1 ? false : 
                matrix[r - 1][0] == target ? 
                true : isTargetRowContainsTarget(matrix, targetRow, target);
    }
    
    bool isTargetRowContainsTarget(vector<vector<int>>& m, int row, int target){
        
        int start = 0;
        int end = m[0].size() - 1;
        
        while(start <= end){
            if(m[row][start] == target || m[row][end] == target)
                return true;
            
            if(m[row][start] > target || m[row][end] < target)
                break;
            
            ++start;
            --end;
        }
        
        return false;
    }
};

/*
Approach:

    find the last row which has it's first values less than target (this is our target row)
    
    search from both ends in target row, (break the search and return false IF target is not in range)
    after whole search if value matched then return true else false;
*/
