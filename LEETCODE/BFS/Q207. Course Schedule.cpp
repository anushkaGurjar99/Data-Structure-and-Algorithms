/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/course-schedule

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
        
        for(int i = 0; i < numCourses; i++){
            if(sequence.find(i) != sequence.end() && courseStatus[i] != 1 && !helper(sequence, courseStatus, i))
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
