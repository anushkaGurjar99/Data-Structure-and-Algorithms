/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/unique-paths/

class Solution{
public:
    int uniquePaths(int m, int n){
        
        if(m == 0 || n == 0)
            return 0;
        
        vector<int> path(m, 1);
        
        for(int i = 1; i < n; i++)                          // row 1 already discovered
            getUniquePathOfCurrentRow(path);
        
        return path[m - 1];        
    }
    
    void getUniquePathOfCurrentRow(vector<int>& path){
        for(int i = 1; i < path.size(); i++)
            path[i] = path[i] + path[i - 1];
    }    
};

/*  
Intution:

Lets take an example of (3 * 3) matrix
we know that for each cell we have 2 ways to reach out:
    - top cell path
    - left cell path

    1   -   -
    -   -   -
    -   -   -           (initially), becuase there is only one path to reach first cell
    
    
    To get unique path for a cell sum up : (left path + top path)

   (1)  1   1
    1   2   3
    1   3  (6)
  

Note: we can create a 2D matrix too.

-- Similar to climibing stairs.
*/
