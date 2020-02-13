/*
 * Author : Anuska Gurjar
 * Date   : Februaruy 2020
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

// Problem Statement: https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> nodes;
        
        if(!root)
            return values;
        
        TreeNode* current = root;
        nodes.push(root);
        
        while(!nodes.empty()){
            TreeNode* curr = nodes.top();
            values.push_back(curr->val);
            nodes.pop();
            if(curr->right)
                nodes.push(curr->right);
            if(curr->left)
                nodes.push(curr->left);
        }
        return values;
    }
};
