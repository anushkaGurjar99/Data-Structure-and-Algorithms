/*
 * Author : Anushka Gurjar
 * Date   : September 2020
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
// Problem Statement: https://leetcode.com/problems/count-good-nodes-in-binary-tree/


class Solution{
public:
    int goodNodes(TreeNode* root){
        return helper(root, root->val);
    }
    
    int helper(TreeNode* node, int val){
        if(!node)
            return 0;
       
        int current = 0;
        if(node->val >= val)
            current = 1;
        
        val = max(val, node->val);
        int l = helper(node->left, val);
        int r = helper(node->right, val);
        
        return l + r + current;
    }
};

/*
Keep track of max-node value in the path(root to X), 
if current node is >= max-node we incldue it in result

each time we update max-node by checking current node.

                3
            1       4
        3           9   5
*/

