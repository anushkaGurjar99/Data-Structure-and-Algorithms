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

// Problem Statement: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        ans = 1;
        depth(root);
        return ans - 1;
    }
    int depth(TreeNode *node){
        if (node == nullptr) return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
};
