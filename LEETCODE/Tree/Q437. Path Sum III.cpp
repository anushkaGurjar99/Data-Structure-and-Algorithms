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

// Problem Statement: https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> path;
        return help(root, sum, path, 0);
    }
    
    int help(TreeNode* node, int sum, unordered_map<int, int>& path, int pre) {
        if (!node) return 0;
        node->val += pre;
        int res = (node->val == sum) + (path.count(node->val - sum) ? path[node->val - sum] : 0);
        path[node->val]++;
        res += help(node->left, sum, path, node->val) + help(node->right, sum, path, node->val);
        path[node->val]--;
        return res;
    }
};

// Same as: Given a target K find subAraay which sum-up equal to K.
