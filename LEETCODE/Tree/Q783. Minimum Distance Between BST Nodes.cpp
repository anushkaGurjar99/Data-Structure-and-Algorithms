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
// Problem Statement: https://leetcode.com/problems/minimum-distance-between-bst-nodes

class Solution {
  public:
    int minDiffInBST(TreeNode *root) {
        int res = INT_MAX, prev = -1;
        helper(root, prev, res);
        return res;
    }

    void helper(TreeNode *node, int &prev, int &res) {
        if (node) {
            helper(node->left, prev, res);
            if (prev != -1) {
                res = min(res, node->val - prev);
            }
            prev = node->val;
            helper(node->right, prev, res);
        }
    }
};
