/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
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

// Problem Statement: https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    int countNodes(TreeNode* root){
        if(!root)
            return 0;
        
        int left = 0;
        int right = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        
        while(l){
            l = l->left;
            left++;
        }
        
        while(r){
            r = r->right;
            right++;
        }
        
        if(left == right)
            return pow(2, left) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/* 
The subtree of a complete binary tree is also a complete binary tree.
So, there are logN levels, every level needs logN time, the whole time complexity is O(logN * logN).
*/


