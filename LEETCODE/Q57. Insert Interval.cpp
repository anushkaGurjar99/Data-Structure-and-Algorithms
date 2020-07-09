/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/insert-interval/

class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        
        if(intervals.size() < 1)
            return {newInterval};
        
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > newInterval[0]){
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
            
            if(i == intervals.size() - 1){
                intervals.push_back(newInterval);
                break;
            }
        }

        return mergeIntervals(intervals);
    }
    
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
        
        vector<vector<int>> result;
        
        for(int i = 0; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            while(i + 1 < intervals.size() && end >= intervals[i + 1][0]){
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            
            result.push_back({start, end});
        }
        
        return result;
    }
    
};

/*
Approach:
    We know that intervals are sorted, so place the newInterval into those intervals. (Pass 1)
    Perform the same merge-interval. (Pass 2)
*/

