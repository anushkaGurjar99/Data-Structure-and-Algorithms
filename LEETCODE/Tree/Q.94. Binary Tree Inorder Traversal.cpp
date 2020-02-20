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

// Problem Statement: https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> values;
        if(!root) 
            return values;
        
        TreeNode* temp = root;
        stack<TreeNode*> nodes;
        
        while(true){
            while(temp){
                nodes.push(temp);
                temp = temp->left;
            }
            
            if(nodes.empty()) 
                break;
            
            temp = nodes.top();
            nodes.pop();
            values.push_back(temp->val);
            temp = temp->right;
        }
        return values;
    }
};

