/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/word-search/

class Solution{
public:
    bool exist(vector<vector<char>>& board, string word){
                
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(wordSearch(board, word, 0, r, c))
                    return true;
            }
        }
        return false;
    }
    
    bool wordSearch(vector<vector<char>>& board, string word, int i, int r, int c){
        
        if(i == word.size())
            return true;
        
        if(r >= board.size() || r < 0)
            return false;
        
        if(c >= board[0].size() || c < 0)
            return false;
        
        if(board[r][c] != word[i])
            return  false;
        
        char curr = board[r][c];
        board[r][c] = ' ';
        
        bool res = false;
        res = res || wordSearch(board, word, i+1, r-1, c);      // top
        res = res || wordSearch(board, word, i+1, r+1, c);      // bottom
        res = res || wordSearch(board, word, i+1, r, c-1);      // left
        res = res || wordSearch(board, word, i+1, r, c+1);      // right
        
        board[r][c] = curr;
        
        return res;
    }
};


/*
The complexity will be O(m∗n∗4^s) where m is the no. of rows and n is the no. of columns in the 
2D matrix and s is the length of the input string.

When we start searching from a character we have 4 choices of neighbors for the first character 
and subsequent characters have only 3 or less than 3 choices but we can take it as 4 (permissible
slopiness in upper bound). This slopiness would be fine in large matrices. So for each character we
have 4 choices. Total no. of characters are s where s is the length of the input string. So one
invocation of search function of your implementation would take O(4s) time.

Also in worst case the search is invoked for m∗n times. So an upper bound would be O(m∗n∗4s).

How does reference copy of this board making any diff to value copy? (TLE on value copy)
*/
