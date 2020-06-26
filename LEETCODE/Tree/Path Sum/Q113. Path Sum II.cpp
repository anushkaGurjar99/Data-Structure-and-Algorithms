/*
 * Author : Anushka Gurjar
 * Date   : February 2020
 * flags    : -std=c++14
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

// Problem Statement: https://leetcode.com/problems/path-sum-ii

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> currPath;
        getAllTargetPaths(root, sum, currPath, result);
        return result;
    }
    void getAllTargetPaths(TreeNode* node, int sum, vector<int> currPath, vector<vector<int>>& result){
        if(!node)
            return;
        currPath.push_back(node->val);
        sum -= node->val;
        if(sum == 0 && !node->left && !node->right)
            result.push_back(currPath);
        getAllTargetPaths(node->left, sum, currPath, result);
        getAllTargetPaths(node->right, sum, currPath, result);
    }
};
