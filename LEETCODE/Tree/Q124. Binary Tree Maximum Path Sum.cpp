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

// Problem Statement: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution{
public:
    int maxPathSum(TreeNode* root){
        int result = INT_MIN;
        helper(root, result);
        return result;
    }
    
    int helper(TreeNode* node, int& result){
        if(!node)
            return 0;
        
        int l = node->val + helper(node->left, result);
        int r = node->val + helper(node->right, result);
        
        result = max(result, node->val);
        result = max(result, l);
        result = max(result, r);
        result = max(result, l + r - node->val);
        
        return max(l, max(r, node->val));
    }
};

/*  
    4 cases to get maxSum 
    node + l + r, node + l, node + r, node, some-prev-max
*/
        
