/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height){
        if(height.size() <= 1)
            return 0;
        
        stack<int> area;
        int water = 0;
        int start = height[0];
        
        for(int i = 1; i < height.size();){
            if(height[i] < start){
                area.push(height[i]);
                i++;
            }
            else{
                while(!area.empty()){
                    water += (start - area.top());
                    area.pop();
                }
                
                start = height[i];
                i++;
            }
        }
        
        if(!area.empty()){
    
            start = area.top();
            area.pop();
            while(!area.empty()){
                if(area.top() < start)
                    water += (start - area.top());
                else
                    start = area.top();
                
                area.pop();
            }
            
        }
        
        return water;
    }
};
