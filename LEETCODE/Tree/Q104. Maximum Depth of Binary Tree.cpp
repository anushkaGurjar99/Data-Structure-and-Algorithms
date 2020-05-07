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
// Problem Statement: https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution{
public:
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return max(l, r) + 1;
    }
};
