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
// Problem Statement: https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
public:
    int kthSmallest(TreeNode* root, int k){
        return find(root, k);
    }
    
    int find(TreeNode* node, int& k){
        if(!node)
            return 0;
        
        int left = find(node->left, k);
        
        k--;
        if(k == 0)
            return node->val;
        
        int right = 0;
        
        if(k > 0)                                    // If kth element not found in left subTree, then only visit right subTree
            right = find(node->right, k);
        
        return (left > right) ? left : right;       // left, right => (result, 0) or (0, result)
    }
};
