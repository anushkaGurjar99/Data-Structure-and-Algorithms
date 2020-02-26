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

// Problem Statement: https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        getFlatten(root, prev);
    }
    void getFlatten(TreeNode* root, TreeNode*& prev){
        if(!root)
            return;
        
        if(root)
            prev = root;
        
        getFlatten(root->left, prev);
        
        TreeNode* right = root->right;
        
        if(root->left){
            root->right = root->left;
            prev->right = right;
            root->left = nullptr;
        }
        
        getFlatten(right, prev);        
    }
};
/*
Keep Remembering the bottom node(always a leaf) where we need to connect to original right child of a node.
Make left child as right child and connect the bottom node to original right child.
                 2
               /  \
              3    6
               \
                10
(For example In this case, 
                            remeber 10  
                            update 3 as right child of 2
                            then connect 10 with 6.)
*/


// ************************************ Approach 2: In Function ************************************
class Solution {
public:
    void flatten(TreeNode* root){
         if(!root)
             return;
        
        flatten(root->left);
        
        TreeNode* temp = root->right;
        
        if(root->left){
            root->right = root->left;
            root->left = nullptr;
            while(root->right)
                root = root->right;
            root->right = temp;
        }
        
        flatten(temp);
    }
};
/*
                 2
               /  \
              3    6
               \
                10
(For example In this case, 
                            store right node(6) in a TEMP
                            update 3 as right child of 2
                            keep going to the right of 3, till leaf node found(10)
                            then connect 10 with 6)
*/
