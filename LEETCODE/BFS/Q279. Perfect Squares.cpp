/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n){
        if(n == 0)
            return 0;
        
        vector<int> square;
        for(int i = 1; i*i <= n; i++){
            square.push_back(i*i);
        }
        
        int squaresRequired = 1;
        int endOfLevel = 0;
        bool isFound = false;
        queue<int> q;
        
        q.push(n);
        q.push(endOfLevel);
        // as first level contain the origianl number only
        
        while(1){
            int curr = q.front();
            q.pop();
            
            if(curr == endOfLevel){           // haven't found the match, visit one more level
                squaresRequired++;
                q.push(endOfLevel);           // push a marker at end of level
            }
            else{
                for(int i = 0; i < square.size() && square[i] <= curr; i++){
                    if(square[i] == curr){
                        isFound = true;
                        break;
                    }
                    q.push(curr - square[i]);  // storing differences from square[i] so that it can be found in next iteration
                }
            }
            if(isFound)
                break;
        }
        
        return squaresRequired;
    }
};
