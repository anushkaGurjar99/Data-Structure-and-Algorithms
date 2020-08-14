/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

// Problem Statement: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

typedef pair<int, int> P;

class Solution{
    
private:
    struct comparator{
        bool operator()(const P& x, const P& y){
            if(x.first != y.first)
                return x.first < y.first;
            return x.second < y.second;
        }
    }comp;
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        
        unordered_map<int, vector<P>> m;
        dfs(root, m, 0, 0);
        
        int limit = m.size() - 1;
        vector<vector<int>> result(limit + 1);
        int pos = 0;
        
        for(int i = -limit; i <= 0; i++){
            if(m.find(i) != m.end())
                getData(m[i], result, pos);
        }
        
        for(int i = 1; i <= limit; i++){
            if(m.find(i) != m.end())
                getData(m[i], result, pos);
        }
        
        return result;
    }
    
    void dfs(TreeNode* node, unordered_map<int, vector<P>>& m, int level, int weight){
        if(!node)
            return;
        
        m[weight].push_back({level, node->val});
        
        dfs(node->left, m, level + 1, weight - 1);
        dfs(node->right, m, level + 1, weight + 1);
    }
    
    void getData(vector<P>& arr, vector<vector<int>>& result, int& pos){
        sort(arr.begin(), arr.end(), comp);
        
        for(auto itr: arr)
            result[pos].push_back(itr.second);
        
        pos++;
    }
};

/*
    DFS: store each vertical-level in a MAP with the level number
    
    HELPER:
        sort each vertical-level using the level-number and node-value.
        store the sorted data into result.
*/



