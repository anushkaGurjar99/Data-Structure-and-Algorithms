/*
 * Author : Anushka Gurjar
 * Date   : August 2020
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

// Problem Statement: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

class Solution{
public:
    int maxAncestorDiff(TreeNode* root){
        if(!root)
            return 0;
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode* node, int high, int low){
        if(!node)
            return 0;
        
        int diff = max(abs(node->val - high), abs(node->val - low));
        high = max(node->val, high);
        low = min(node->val, low);
        
        int l = dfs(node->left, high, low);
        int r = dfs(node->right, high, low);
        
        return max(diff, max(l, r));
    }
};

/*
    LOW and HIGH denoting the max and min value in that path.
    each time we reach a not-null node ->   calculate node diff with high and low
                                            calculate left subtree result
                                            calculate right subtree result
    at last return the maximum of all 3.
*/

