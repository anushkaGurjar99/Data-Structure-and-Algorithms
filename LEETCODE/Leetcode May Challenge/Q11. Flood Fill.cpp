/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        fillConnectedSpace(image, sr, sc, image[sr][sc], newColor);
        return image; 
    }
    
    void fillConnectedSpace(vector<vector<int>>& image, int row, int col, int target, int newColor){

        //cout<<"\n"<<sr<<' '<<sc;
        
        if(row == image.size() || row < 0)
            return;
        
        if(col == image[row].size() || col < 0)
            return;
        
        if(image[row][col] != target || newColor == target)   
            return;
        
        image[row][col] = newColor;
        
        fillConnectedSpace(image, row + 1, col, target, newColor);        // top
        fillConnectedSpace(image, row - 1, col, target, newColor);        // bottom
        fillConnectedSpace(image, row, col + 1, target, newColor);        // right
        fillConnectedSpace(image, row, col - 1, target, newColor);        // left
    }
};


/*
    check all 4 directions from given [row][col]
    recurse from valid states
    ----------------------------------------------------
     
    Return cases:
        invalid row
        invalid column
        current cell is not target || current cell is already filled with newColor
*/


