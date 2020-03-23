/*
 * Author : Anushka Gurjar
 * Date   : March 2020
 * flags    : -std=c++14
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        if(target == "0000")
            return 0;
        
        unordered_set<string> visited;     // O(1) average and best search time complexity, store all visited locks
        for(auto itr: deadends)
            visited.insert(itr);
        
        queue<string> q;        // get all combinations in here
        
        if(visited.find("0000") == visited.end()){
            q.push("0000");
            visited.insert("0000");
        }
        
        string levelMarker = "null";
        q.push(levelMarker);
        
        int rotations = 1;          // rotations to be done
        
        while(!q.empty()){
            string currLock = q.front();
            q.pop();
            
            if(currLock == levelMarker){                         // if level is over, incr the rotation
                if(q.empty())
                    break;
                
                rotations++;
                q.push(levelMarker);
            }
            else{
                for(int i = 0; i < 4; i++){                      // 4 positions to be checked
                    string next = getMove(currLock, i, true);
                    string prev = getMove(currLock, i, false);
                    
                    if(next == target || prev == target)
                        return rotations;
                    
                    if(visited.find(next) == visited.end()){
                        visited.insert(next);
                        q.push(next);
                    }
                    
                    if(visited.find(prev) == visited.end()){
                        visited.insert(prev);   
                        q.push(prev);
                    }
                } 
            }
        }
        
        return -1;
    }
    
    string getMove(string currLock, int pos, bool isIncrementalMove){   
        char ch = currLock[pos];
        
        if(isIncrementalMove)
            currLock[pos] = (ch == '9') ? '0' : ++currLock[pos];            // incr by 1
        else
            currLock[pos] = (ch == '0') ? '9' : --currLock[pos];            // decr by 1
            
        return currLock;
    }
};
