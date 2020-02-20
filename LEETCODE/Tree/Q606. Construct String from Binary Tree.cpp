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

// Problem Statement: https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        if(!t->right && !t->left)
            return to_string(t->val);
        if(!t->right)
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};
