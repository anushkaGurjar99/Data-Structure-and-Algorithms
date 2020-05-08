/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution{
public:
    bool checkStraightLine(vector<vector<int>>& c){
        if(c.size() <= 2) 
            return true;
        
        float x0 = c[0][0];
        float y0 = c[0][1];
        float x1 = c[1][0];
        float y1 = c[1][1];
        
        float slope = (y1 - y0) / (x1 - x0);
        
        for(int i = 2; i < c.size(); i++){
            float x = c[i][0];
            float y = c[i][1];
            if((y - y0) / (x - x0) != slope)
                return false;
        }
        return true;
    }
};

/*
If there are only 2 points we can return True as 2 points will always have a straight Line

Else
    c1 with c2
    c1 with c3
    ..........
    c1 with cn
    
    if(slope1 is not equal to slope2)
        return false
        
        
    y1 - y0                 y - y0
    _______       ==        _______
    x1 - x0                 x - x0
*/

