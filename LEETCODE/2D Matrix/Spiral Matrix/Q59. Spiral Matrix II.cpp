/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
     
        enum dir{RIGHT, DOWN, LEFT, UP};
        
        vector<vector<int>> matrix (n, vector<int> (n, 0));
        
        int num = 1;

        int rowBegin = 0;
        int rowEnd = n;
        int colBegin = 0;
        int colEnd = n;

        int r = 0;
        int c = 0;
        dir direction = RIGHT;

        while(num <= n * n){
            
            switch(direction){
                
                case RIGHT:{
                    while(c < colEnd){
                        matrix[r][c] = num++;
                        c++; 
                    }
                    r++;
                    c--;
                    direction = DOWN;
                }
                break;
                    
                case DOWN:{
                    while(r < rowEnd){
                        matrix[r][c] = num++;
                        r++; 
                    }
                    r--;
                    c--;
                    direction = LEFT;
                }
                break;

                case LEFT:{
                    while(c >= colBegin){
                        matrix[r][c] = num++;
                        c--; 
                    }
                    r--;
                    c++;
                    direction = UP;
                }
                break;
                    
                case UP:{
                    while(r > rowBegin){
                        matrix[r][c] = num++;
                        r--;
                    }
                    r++;
                    c++;
                    rowBegin++;
                    colBegin++;
                    rowEnd--;
                    colEnd--;
                    direction = RIGHT;
                }
                break;
            }
        }
        return matrix;
    }
};

/*
Create a N*N matrix filled with all zeros.
Modify cell values by Traversing in Spiral order.
*/
