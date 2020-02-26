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

// Problem Statement: https://leetcode.com/problems/binary-tree-pruning

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root){
        bool result = letsPrune(root);
        return result ? root : nullptr;
    }
    bool letsPrune(TreeNode* node){
        if(!node)
            return 0;
        
        bool left = letsPrune(node->left);
        bool right = letsPrune(node->right);
        
        if(!left){
            node->left = nullptr;    
            delete node->left;
        }
        if(!right){
            node->right = nullptr;
            delete node->right;
        }
        return node->val || left || right;
    }
};

// ********************************** Approach 2: InFunction **********************************
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root){
            if(!root)
            return nullptr;
        
        TreeNode* left = pruneTree(root->left);
        TreeNode* right = pruneTree(root->right);
        
        if(!left){
            root->left = nullptr;    
            delete root->left;
        }
        if(!right){
            root->right = nullptr;
            delete root->right;
        }
        
        if(left)
            return root;
        else if(right)
            return root;
        else
            return (root->val == 0) ? nullptr : root;
    }
};

