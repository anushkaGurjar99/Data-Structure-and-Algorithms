/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/merge-intervals/

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        
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
Similar ques: https://leetcode.com/problems/insert-interval/

Approach:
    Sort the array
    Remove the conflicts
        case1: If start time of next interval is smaller than finish time of prev-interval(s)
            update the finish time in each iteration
            ([1,10], [2,3], [5,6]) => ([1, 10])
*/

