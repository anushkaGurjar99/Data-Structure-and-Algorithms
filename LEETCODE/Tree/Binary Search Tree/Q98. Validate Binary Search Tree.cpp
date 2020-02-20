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
// Problem Statement: https://leetcode.com/problems/validate-binary-search-tree

class Solution {
public:
    bool validateRange(TreeNode* node, TreeNode* minNode, TreeNode* maxNode){

        // base case
        if(!node) 
            return true;

        // is node in range or not
        if(minNode && node->val <= minNode->val){ return false; }
        if(maxNode && node->val >= maxNode->val){ return false; }

        // verify left and right subTree
        return validateRange(node->left, minNode, node) && validateRange(node->right, node, maxNode);
    }
    bool isValidBST(TreeNode* root){
        return validateRange(root, nullptr, nullptr);
    }
};
