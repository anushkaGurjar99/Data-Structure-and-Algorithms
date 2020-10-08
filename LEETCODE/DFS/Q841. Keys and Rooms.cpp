/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/keys-and-rooms/

class Solution{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        
        int size = rooms.size();
        vector<bool> v(size, 0);
        dfs(rooms, v, 0);
        
        for(auto itr: v){
            if(!itr)
                return false;
        }
        
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& v, int curr){
        if(v[curr])
            return;
        
        v[curr] = true;
        
        for(auto itr: rooms[curr]){
            if(!v[itr])
                dfs(rooms, v, itr);
            v[itr] = true;
        }
    }
};

/*
    take an array of which shows particular room is visited or not.
    visit all possible rooms using DFS.
    at last check all rooms are visited or not.
*/
