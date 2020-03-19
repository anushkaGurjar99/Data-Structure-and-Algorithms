/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    bool flip;
    void solve(vector<vector<char>>& board){
        
        // can't update the region of 0 to 2 size
        if(board.size() < 3)
            return;
        
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                
                if(board[row][col] == 'O'){
                    flip = true;
                    
                    flipRegion(board, row, col, 'O', 'T');              // mark the region T
                    
                    if(flip)                                            // flip if region is valid
                        flipRegion(board, row, col, 'T', 'X');                  
                }
            }
        }
        
        // restore invalid region
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                
                if(board[row][col] == 'T')
                    board[row][col] = 'O';
            }
        }
        
    }
        
    void flipRegion(vector<vector<char>>& board, int row, int col, char from, char to){
            
        if(row < 0 || row == board.size())
            return;
            
        if(col < 0 || col == board[row].size())
            return;
        
        // mark the region invalid but still we can't reture as we have to cover whole invalid region
        if(board[row][col] == 'O' && (row == 0 || row == board.size() - 1 || col == 0 || col == board[row].size() - 1))
            flip = false;
            
        if(board[row][col] == from){
            board[row][col] = to;
                
            flipRegion(board, row + 1, col, from, to);        // bottom region
            flipRegion(board, row - 1, col, from, to);        // top region
            flipRegion(board, row, col + 1, from, to);        // right region
            flipRegion(board, row, col - 1, from, to);        // left region
        }
    }
    
};
