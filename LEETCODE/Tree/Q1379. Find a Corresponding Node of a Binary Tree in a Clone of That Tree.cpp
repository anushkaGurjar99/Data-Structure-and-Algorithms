/*
 * Author : Anushka Gurjar
 * Date   : August 2020
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

// Problem Statement: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

class Solution{
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target){
        
        if(!original)
            return nullptr;
        
        if(cloned->val == target->val && isSame(original, cloned))
            return cloned;
        
        TreeNode* l = getTargetCopy(original->left, cloned->left, target);
        TreeNode* r = getTargetCopy(original->right, cloned->right, target);
        
        return (l) ? l : r;
    }
    
    bool isSame(TreeNode* A, TreeNode* B){
        if(!A && !B)
            return true;
        
        if(!A || !B)
            return false;
        
        if(A->val != B->val)
            return false;
        
        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }
};

// Follow-up
// check the values and structure of tree. If matched returned the cloned pointer.


