/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++14
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

// Problem Statement: https://leetcode.com/problems/find-bottom-left-tree-value/

class Solution{
public:
    int findBottomLeftValue(TreeNode* root){
        int maxDepth = -1;
        int result = 0;
        dfs(root, result, maxDepth, 0);
        return result;
    }
    
    void dfs(TreeNode* node, int& result, int& maxDepth, int currDepth){
        if(!node)
            return;
        
        if(maxDepth < currDepth){
            maxDepth = currDepth;
            result = node->val;
        }
        
        dfs(node->left, result, maxDepth, currDepth + 1);
        dfs(node->right, result, maxDepth, currDepth + 1);
    }
    
};

/*
Store the deepest level first node into result.
*/

// iterative app: using queue
