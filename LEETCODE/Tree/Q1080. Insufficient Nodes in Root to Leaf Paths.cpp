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
// Problem Statement: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

class Solution{
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit){
        if(!root)
            return nullptr;
        
        return dfs(root, limit, 0) ? nullptr: root;
    }
    
    bool dfs(TreeNode* node, int& limit, int sum){
        
        sum += node->val;
        
        if(!node->left && !node->right)
            return sum < limit ? true : false;
        
        bool l = (node->left)  ? dfs(node->left, limit, sum)  : true;
        bool r = (node->right) ? dfs(node->right, limit, sum) : true;
        
        if(l)
            node->left = nullptr;
        if(r)
            node->right = nullptr;
        
        return (l && r) ? true : false;
    }  
};

/*
Appraoch:
    base case:  if you have reached the leaf node and pathSum is less than limit
                return true. (that means yes we want to remove this path)
                
    left result = traverse the left subTree if exist else init to TRUE
    do same for right
    
    if left is TRUE -> that means path is invalid so we mark the left child null
    do same for right
    
    if both right and left paths are invalid then we have to remove currNode so we return true.
    (remember what we do to true)
*/
