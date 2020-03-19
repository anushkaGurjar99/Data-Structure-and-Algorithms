/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/course-schedule

/* TOPOLOGICAL SORTING */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> sequence;
        vector<int> degree(numCourses, 0);
        vector<int> result;
        
        // store all dependencies and degree of each course
        for(auto& coursePair: prerequisites){
            int independent = coursePair[1];
            int dependent = coursePair[0];
            
            sequence[independent].push_back(dependent);
            degree[dependent]++;
        }
        
        // store all independent courses, as they come first in topological sorting
        queue<int> order;
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                order.push(i);
                result.push_back(i);
            }
        }
        
        
        
        while(!order.empty()){
            
            int curr = order.front();
            order.pop();
            
            for(auto& next: sequence[curr]){
                degree[next]--;                    // decrement the dependencies;
                if(degree[next] == 0){             // keep storing independent courses
                    order.push(next);
                    result.push_back(next);
                }
            }
        }
        
        vector<int> temp;
        return (result.size() == numCourses) ? result : temp;
    }
};
