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
        
        if(!area.empty()){                              // when you have visited whole points and no bigger point found
    
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
// Keep pushing the smaller than 'i' area into stack, if you discovered a point which is greater than 'i' or whole points visited, then collect water.


// ********************************* Two Pointer Approach *********************************
class Solution {
public:
    int trap(vector<int>& height){
        
        if(height.size() <= 1)
            return 0;
        
        int waterCollected = 0;
        
        int start = 0;
        int end = height.size() - 1;
        int head = height[start];
        int tail = height[end];
        
        while(start < end){
            
            if(height[start] < height[end]){
                start++;
                if(height[start] < head)
                    waterCollected += head - height[start];
                else
                    head = height[start];
            }
            else{
                end--;
                if(height[end] < tail)
                    waterCollected += tail - height[end];
                else
                    tail = height[end];
            }
        }
        
        return waterCollected;
    }
};

/*
Two pointer approach ('start' and 'end')
    
    move the pointer which is lesser 
    After moving, 
    if the element is less than 'head' or 'tail'
        add the water(diffenence) into container
    else
        make the element as 'head' or 'tail'
    this shows that how much the maximum water we can collect
    terminate the loop when start == end
    
*/

// keep adding from the point which is smaller and collect in waterCollected.
