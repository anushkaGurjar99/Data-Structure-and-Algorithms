/*
 * Author : Anushka Gurjar
 * Date   : May 2020
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
// Problem Statement: https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int minDepth(TreeNode* root){
        if(!root)
            return 0;
        
        if(!root->left)
            return minDepth(root->right) + 1;
        else if(!root->right)
            return minDepth(root->left) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;   
    }
};

