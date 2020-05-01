/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        
        if(heights.size() < 1)
            return 0;
        
        stack<int> area;
        int result = heights[0];
        int curr = heights[0];
        
        for(int i = 0; i < heights.size(); i++){
            
            if(!area.empty() && heights[i] < heights[area.top()]){    
                curr = getArea(area, heights, i);
                result = max(curr, result);
            }
            
            area.push(i);
        }
        
        // *
        if(!area.empty()){                               
            heights.push_back(0);
            curr = getArea(area, heights, heights.size() - 1);
            result = max(curr, result);
            heights.pop_back();
        }
        
        return result;
    }
    
    int getArea(stack<int>& area, vector<int> h, int i){
        
        int localMax = 0;
        
        while(h[area.top()] > h[i]){                            
            int bar = area.top();
            area.pop();
            
            if(area.empty()){                                   
                localMax = max(localMax, h[bar] * (i));
                break;
            }
            
            int l = bar - area.top() - 1;                      
            int r = (i - bar);
            
            localMax = max(localMax, (h[bar] * l) + (h[bar] * r));
        }
        
        return localMax;
    }
    
};

/*
Approach:

thoughtout all we will be working with indices because we need to calculate area for each bar.

Store the increasing order of bar in stack (index) 
as soon as you found the non-sequential bar (say k), start calculating the area
    
    ( How do you cal the area and how is it working?
    The sequential bar makes it easier to calculate left and right area of individual. )

    loop through stack till top of stack is < current bar(non-sequential)
    
    IF stack has only one element left then it is the minimum bar till current so 
    just multiply the height[top] with current index.
    
    ELSE calculate right and left range using indexes 
     (left range found by top of the stack, right range found by number of elements between bar and k)
    
    compare current bar area with maxarea;
    

*
If no sequential bar found,
    push a temporary element 0 (least among non- -ve integers)
    then follow same as above
*/


// ******************************************* Brute Force **************************************************

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        if(heights.size() < 1)
            return 0;
        
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            
            int currArea = heights[i];
            
            for(int left = i - 1; left >= 0 && heights[i] <= heights[left]; left--)
                currArea += heights[i];
                
            for(int right = i + 1; right < heights.size() && heights[i] <= heights[right]; right++)
                currArea += heights[i];
                
            maxArea = max(currArea, maxArea);
        }
        
        return maxArea;
    }
};


// calculate left and right compatible range for each bar
