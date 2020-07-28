/*
 * Author : Anushka Gurjar
 * Date   : July 2020
 * flags  : -std=c++17
*/


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/problems/delete-leaves-with-a-given-value/

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target){
        if(!root)
            return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(!root->left && !root->right && root->val == target)
            return nullptr;
        
        return root;
    }
};

/*
    approach:
        curr->left = root->left subtree
        curr->right = root->right subtree
        
        check if curr node is leaf and equals to target
            return null
            
        return curr
*/
