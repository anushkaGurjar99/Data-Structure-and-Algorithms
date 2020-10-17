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
// Problem Statement: https://leetcode.com/problems/longest-univalue-path
 

class Solution{
public:
    int longestUnivaluePath(TreeNode* root){
        int res = 0;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* node, int& res){
        if(!node)
            return 0;
        
        int l = helper(node->left, res);
        int r = helper(node->right, res);
        
        l = (node->left && node->left->val == node->val) ? l + 1 : 0;
        r = (node->right && node->right->val == node->val) ? r + 1 : 0;
        
        res = max(res, l + r);
        return max(l, r);
    }
};


// ********************************************************************************************************************************************************************

class Solution{
public:
    int longestUnivaluePath(TreeNode* root){
        int res = 0;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* node, int& res){
        if(!node)
            return;
        
        int p = longest(node->left, node->val) + longest(node->right, node->val) + 1;
        res = max(p - 1, res);
        
        helper(node->left, res);
        helper(node->right, res);
    }
    
    int longest(TreeNode* node, int& val){
        if(!node)
            return 0;
        
        if(node->val != val)
            return 0;
        
        int l = longest(node->left, val);
        int r = longest(node->right, val);
        
        return max(l, r) + 1;
    }
};
