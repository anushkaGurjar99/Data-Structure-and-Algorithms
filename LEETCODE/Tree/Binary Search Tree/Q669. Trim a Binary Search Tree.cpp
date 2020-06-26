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
// Problem Statement: https://leetcode.com/problems/trim-a-binary-search-tree/

class Solution {
public:
    TreeNode* trimBST(TreeNode* node, int L, int R){
        if(!node) 
            return node;                                // Go to bottom of tree. Do nothing with this returned value
    
        node->left = trimBST(node->left, L, R);
        node->right = trimBST(node->right, L, R);
        
        if(node->val < L || node->val > R){             // node->val is not in Range, overwrite the node
            if(node->left)
                node = node->left; 
                
            else if(node->right)
               node = node->right; 
            
            else if (!node->right && !node->left)       // node has no children
                node = nullptr;  
        }
        return node;
    }
};
