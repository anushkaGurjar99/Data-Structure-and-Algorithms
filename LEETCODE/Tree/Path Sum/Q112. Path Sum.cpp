/*
 * Author : Anushka Gurjar
 * Date   : June 2020
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

// Problem Statement: https://leetcode.com/problems/path-sum/

class Solution{
public:
    bool hasPathSum(TreeNode* root, int sum){
        if(!root)
            return false;
        
        sum -= root->val;
        bool targetFound = (sum == 0 && !root->left && !root->right) ? true: false;
        
        return targetFound || hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
