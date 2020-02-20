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

// Problem Statement: https://leetcode.com/problems/binary-tree-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        
        vector<vector<int>> levelOrder;
        if(!root)
            return levelOrder;
        
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            vector<int> values;
            int size = nodes.size();
            for(int i = 0; i < size; i++){
                TreeNode* data = nodes.front();
                values.push_back(data->val);
                nodes.pop();
                
                if(data->left)
                    nodes.push(data->left);
                if(data->right)
                    nodes.push(data->right);
                
            }
            levelOrder.push_back(values);
        }
        return levelOrder;
    }
};
