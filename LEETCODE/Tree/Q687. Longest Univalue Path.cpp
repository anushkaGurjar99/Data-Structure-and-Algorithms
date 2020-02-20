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
 
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) 
            return 0;
        int longestPath = 0;
        checkPath(root, longestPath);
        return longestPath;
    }
    int checkPath(TreeNode* node, int& num){
        
        int l = node->left ? checkPath(node->left, num) : 0;
        
        int r = node->right ? checkPath(node->right, num) : 0;
        
        l = (node->left && node->left->val == node->val) ? l+1 : 0;
        
        r = (node->right && node->right->val == node->val) ? r+1 : 0;
        
        num = max(num, l+r);
        
        return max(l, r);      
    }
};
