/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        
        unordered_map<int, vector<int>> sequence;
        vector<int> degree(numCourses, 0);
        
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
            if(degree[i] == 0)
                order.push(i);
        }
        
        int coursesObtained = 0;
        
        
        while(!order.empty()){
            coursesObtained++;
            
            int curr = order.front();
            order.pop();
            
            for(auto& next: sequence[curr]){
                degree[next]--;                    // decrement the dependencies;
                if(degree[next] == 0)              // keep storing independent courses
                    order.push(next);
            }
            
        }
        
        return coursesObtained == numCourses;
    }
};




// TIME LIMIT EXCEED, pass all test cases except large one
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        
        unordered_map<int, vector<int>> sequence;
        
        // storing all dependencies of individual course
        for(int i = 0; i < prerequisites.size(); i++)
            sequence[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        return isDependent(sequence, numCourses);
    }
    
    bool isDependent(unordered_map<int, vector<int>> sequence, int numCourses){
        
        // -1 = unvisited, 0 = under process, 1 = visited
        vector<int> courseStatus(numCourses, -1);
        
        // visit only those elements which are in HASH MAP
        for(auto const& curr: sequence){
            if(courseStatus[curr.first] != 1 && !helper(sequence, courseStatus, curr.first))
                return false;
        }
        
        return true;
    }
    
    bool helper(unordered_map<int, vector<int>> sequence, vector<int>& courseStatus, int i){
        if(courseStatus[i] == -1)
            courseStatus[i] = 0;
        else
            return false;
            
        for(int j = 0; j < sequence[i].size(); j++){
            if(sequence.find(i) != sequence.end() && courseStatus[sequence[i][j]] != 1 && !helper(sequence, courseStatus, sequence[i][j]))
                return false;
        }
        
        courseStatus[i] = 1;
        return true;
    }
};
