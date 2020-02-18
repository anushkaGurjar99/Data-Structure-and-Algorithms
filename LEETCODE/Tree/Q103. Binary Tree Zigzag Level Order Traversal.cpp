/*
 * Author : Anushka Gurjar
 * Date   : Februaruy 2020
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

// Problem Statement: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagOrder;
        
        if(!root)
            return zigzagOrder;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        int ctr = 0;
        
        while(!nodes.empty()){
            vector<int> values;
            int size = nodes.size();
            
            while(size > 0){
                TreeNode* temp = nodes.front();
                values.push_back(temp->val);
                nodes.pop();
                
                if(temp->left)
                    nodes.push(temp->left);
                if(temp->right)
                    nodes.push(temp->right);
                
                size--;
            }
            
            if(ctr % 2 != 0)
                reverse(values.begin(), values.end());
            zigzagOrder.push_back(values);
            ctr++;
        }
        return zigzagOrder;
    }
};
