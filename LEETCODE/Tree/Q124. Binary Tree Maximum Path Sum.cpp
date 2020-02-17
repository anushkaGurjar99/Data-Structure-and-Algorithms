/*
 * Author : Anuska Gurjar
 * Date   : Februaruy 2020
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

class Solution {
public:
    int maxPathSum(TreeNode* root){
        int maxSum = INT_MIN;
        getMaxPathSum(root, maxSum);
        return maxSum;
    }
    int getMaxPathSum(TreeNode* node, int& maxSum){
        if(!node)
            return 0;
        
        int left = node->val + getMaxPathSum(node->left, maxSum);
        int right = node->val + getMaxPathSum(node->right, maxSum);
        
        maxSum = ((left + right - node->val) > maxSum) ? (left + right - node->val) : maxSum;
        maxSum = (left > maxSum) ? left : maxSum;
        maxSum = (right > maxSum) ? right : maxSum;
        maxSum = (node->val > maxSum) ? node->val : maxSum;
        
        return max(node->val, max(left, right));
    }
};

