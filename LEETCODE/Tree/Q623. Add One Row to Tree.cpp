/*
 * Author : Anushka Gurjar
 * Date   : October 2020
 * flags  : -std=c++17
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
// Problem Statement: https://leetcode.com/problems/add-one-row-to-tree/


class Solution{
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d){
        return setLevel(root, v, d - 1, true);
    }
    
    TreeNode* setLevel(TreeNode* node, int& v, int d, bool dirLeft){
        if(d == 0){
            TreeNode *newNode = new TreeNode(v);
            (dirLeft) ? newNode->left = node : newNode->right = node;
            return newNode;
        }
        
        if(!node)
            return nullptr;
        
        node->left = setLevel(node->left, v, d - 1, true);
        node->right = setLevel(node->right, v, d - 1, false);
        return node;
    }
};

/*
Approach:
    find the desired level, keep a directional marker
    add node and return the new subtree
*/
