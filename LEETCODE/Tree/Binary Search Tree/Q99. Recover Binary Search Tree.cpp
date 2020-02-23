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
// Problem Statement: https://leetcode.com/problems/recover-binary-search-tree

class Solution {
public:
    void recoverTree(TreeNode* root){
        TreeNode* one = nullptr;
        TreeNode* two = nullptr;
        TreeNode* prev = nullptr;
        findSwappedNodes(root, prev, one, two);
        int swap = one->val;
        one->val = two->val;
        two->val = swap;
    }
    void findSwappedNodes(TreeNode* curr, TreeNode*& prev, TreeNode*& one, TreeNode*& two){
        if(!curr)
            return;
                
        findSwappedNodes(curr->left, prev, one, two);
        
        if(prev && !one && !two && curr->val < prev->val){
            one = prev;
        }
        if(one && curr->val < prev->val){
            two = curr;
        }
        else{}
        prev = curr;
        
        findSwappedNodes(curr->right, prev, one, two);
    }
};
