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

// Problem Statement: https://leetcode.com/problems/balanced-binary-tree

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        getHeight(root, flag);
        return flag;
    }
    int getHeight(TreeNode* node, bool& flag){
        if(!node)
            return -1;
        int l = getHeight(node->left, flag) + 1;
        int r = getHeight(node->right, flag) + 1;
        if( abs(l - r) > 1){
            flag = false;
            return 0;
        }
        return max(l, r);
    }
};
