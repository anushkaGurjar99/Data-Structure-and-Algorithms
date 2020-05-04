/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int> > &matrix, int target){
    
    int r = 0;
    int c = matrix[0].size() - 1;
    
    while(r < matrix.size() && c >= 0){
        if(matrix[r][c] == target)
            return 1;
        else if(matrix[r][c] < target)
            r++;
        else
            c--;
    }
    return 0;
}

/*
    Find the target row
    Search the target row
*/

// ********************************* Similar approach, with 2 pointers at Target Row ********************************

bool isTargetRowContainsTarget(vector<int> v, int target){
    int start = 0;
    int end = v.size() - 1;
    while(start <= end){
        if(v[start] == target || v[end] == target)
            return true;
        
        if(v[start] > target || v[end] < target)
            break;
        
        ++start;
        --end;
    }
    return false;
}

int Solution::searchMatrix(vector<vector<int> > &matrix, int target){
    
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
            true : isTargetRowContainsTarget(matrix[targetRow], target);
}

/*
Approach:
    find the last row which has it's first values greater than target (this is our target row)    
    search from both ends in target row,    if any time values goes out of current range 
                                            (break the search and return false)
    if value matched return true else false;
*/
