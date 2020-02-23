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

// Problem Statement: https://leetcode.com/problems/binary-tree-right-side-view

class Solution {
public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> result;
        int maxLevel = -1;
        getRightMost(root, result, maxLevel, 0);                 // currentLevel = 0
        return result;
    }
    void getRightMost(TreeNode* node, vector<int>& result, int& maxLevel, int currLevel){
        if(!node)
            return;
        if(maxLevel < currLevel){
            maxLevel = currLevel;
            result.push_back(node->val);
        }
        currLevel++;
        getRightMost(node->right, result, maxLevel, currLevel);
        getRightMost(node->left, result, maxLevel, currLevel);
    }
};
