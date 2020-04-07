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
        
        int row = 0;
        
        while(row < matrix.size()){
            if(row + 1 < matrix.size() && matrix[row][0] <= target && matrix[row + 1][0] <= target){
                row++;
            }
            else{
                for(int col = 0; col < matrix[0].size(); col++){
                    if(matrix[row][col] == target)
                        return true;
                }
                return false;
            }
        }
        
        return false;
    }
};

/*
Approach:
Find the target Row
Then search the target Row
*/
