/*
 * Author : Anushka Gurjar
 * Date   : July 2020
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

// Problem Statement: https://leetcode.com/problems/subtree-of-another-tree/

class Solution{
public:
    bool isSubtree(TreeNode* root, TreeNode* sub){
        if(!root)
            return false;
        
        if(root->val == sub->val){
            if(check(root, sub))
                return true;
        }
        
        return isSubtree(root->left, sub) || isSubtree(root->right, sub);
    }
    
    bool check(TreeNode* root, TreeNode* sub){
        if(!root && !sub)
            return true;
        
        if(!root ^ !sub)
            return false;
        
        if(root->val != sub->val)
            return false;
        
        return check(root->left, sub->left) && check(root->right, sub->right);
    }
};

/*
    check lineraly
*/
