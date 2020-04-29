/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix){
        vector<int> size = binaryMatrix.dimensions();
        
        int col = size[1] - 1;
        int result = INT_MAX;
        
        for(int r = 0; r < size[0]; r++){
            for(int c = col; c >= 0; c--){
                if(binaryMatrix.get(r,c) == 1)
                    result = min(result, c);
                else
                    break;
                col = c;
            }
            if(result == 0)
                return result;
        }
        
        return (result == INT_MAX) ? -1: result;
    }
};


/*
Approach:
Start from top-left corner and keep moving -
    if current cell is 1, then left (because we want minimum)
    else move downwards to check is their any 1 on this column
*/
