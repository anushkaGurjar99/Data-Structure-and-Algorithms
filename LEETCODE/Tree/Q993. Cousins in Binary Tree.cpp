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

// Problem Statement: https://leetcode.com/problems/cousins-in-binary-tree/


class Solution{
public:
    bool isCousins(TreeNode* root, int x, int y){        
        
        TreeNode* p1 = nullptr;
        int h1 = 0;
        if(!func(root, p1, x, h1, 0))
            return false;
        
        TreeNode* p2 = nullptr;
        int h2 = 0;
        if(!func(root, p2, y, h2, 0))
            return false;
        
        return h1 == h2 && p1 != p2;
    }
    
    bool func(TreeNode* node, TreeNode*& parent, int target, int& h, int curr){
        if(!node)
            return false;
        
        h = curr;
        parent = node;
        
        if(node->left && node->left->val == target)
            return true;
        if(node->right && node->right->val == target)
            return true;
        
        return  func(node->left, parent, target, h, curr + 1) || 
                func(node->right, parent, target, h, curr + 1);
    }
};


// compare depth and parent node of both targets
