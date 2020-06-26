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


// ********************************** 2 stack Approach **********************************
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> zigzagOrder;
        
        if(!root)
            return zigzagOrder;
            
        bool leftToRight = false;
        stack<TreeNode*> next;
        vector<int> values;
        stack<TreeNode*> current;
        current.push(root);
        
        while(!current.empty()){            
            TreeNode* temp = current.top();
            current.pop();
            
            values.push_back(temp->val);
                
            if(leftToRight){
                if(temp->right)
                    next.push(temp->right);
                if(temp->left)
                    next.push(temp->left);
            }
            else{
                if(temp->left)
                    next.push(temp->left);
                if(temp->right)
                    next.push(temp->right);
            }
            
            if(current.empty()){
                swap(current, next);
                zigzagOrder.push_back(values);
                leftToRight = !leftToRight;
                values.clear();
            }
        }
        return zigzagOrder;
    }
};
