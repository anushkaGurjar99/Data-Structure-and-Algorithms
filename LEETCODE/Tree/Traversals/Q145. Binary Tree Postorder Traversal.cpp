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

// Problem Statement: https://leetcode.com/problems/binary-tree-postorder-traversal

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(!root)
            return result;
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            TreeNode *current = nodes.top();
            nodes.pop();
            if(current->left)
                nodes.push(current->left);
            if(current->right)
                nodes.push(current->right);
            result.insert(result.begin(), current->val);
        }
        return result;
    }
};
