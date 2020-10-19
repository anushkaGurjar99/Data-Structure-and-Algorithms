/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<vector<int>> res;
        int target = graph.size() - 1;
        dfs(graph, res, target, {0}, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& A, vector<vector<int>>& res, int& target, vector<int> v, int pos){
        if(pos == target){
            res.push_back(v);
            return;
        }
        
        for(int i = 0; i < A[pos].size(); i++){
            v.push_back(A[pos][i]);
            dfs(A, res, target, v, A[pos][i]);
            v.pop_back();
        }
    }
};

/*
    Visit all paths from source
    Store all Source-to-Destination paths
    Return the result
*/

