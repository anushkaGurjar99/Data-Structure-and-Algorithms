/*
 * Author : Anushka Gurjar
 * Date   : May 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/maximal-rectangle/

class Solution{
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        
        if(matrix.size() == 0)
            return 0;
        
        int result = 0;
        int col = matrix[0].size();
        vector<int> histo(col, 0);
        
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < col; c++)
                histo[c] = (matrix[r][c] == '0') ? 0 : ++histo[c];
            
            result = max(getArea(histo), result);
        }
        return result;
    }
    
    int getArea(vector<int>& histo){
        int maxArea = 0;
        int left, right, area, top;
        bool edgeCase = false;
        stack<int> st;
        for(int i = 0; i <= histo.size(); i++){
            if(i == histo.size())
                edgeCase = true;
            while(!st.empty() && (edgeCase || histo[st.top()] > histo[i])){
                top = st.top();
                st.pop();
                left = top - (st.empty() ? 0 : st.top() + 1);
                right = i - top;
                area = (left + right) * histo[top];
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }    
};

/*
Approach:
    we have approached this problem same way as Largest Histogram in an array.
    
    Scan each Row to calculate BARS
        Each time we get 1 -> increment the bar
        Each time we get 0 -> bar value goes to 0
    calculate the 'maxArea' and Update the result

Note: The BAR keeps increasing if continous 1 appear in same column

'maxArea' calculation:
    { if current value is < top of stack 
        pop TOP
        caculate the TOP's area and update the max }
    insert current index into stack
    
    
area calculation:   we are storing incre order of elements in stack
                    Right: for each TOP we know it supports area len from TOP to curr
                    Left: from TOP to next top
*/


