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
// Problem Statement: https://leetcode.com/problems/convert-bst-to-greater-tree

class Solution {
public:
    TreeNode* convertBST(TreeNode* root){
        int sum = 0;
        getGreaterBST(root, sum);
        return root;
    }
    void getGreaterBST(TreeNode* node, int& sum){
        if(!node)
            return;
        getGreaterBST(node->right, sum);
        sum += node->val;
        node->val = sum;
        getGreaterBST(node->left, sum);
    }
};
