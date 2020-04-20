/*
 * Author : Anushka Gurjar
 * Date   : April 2020
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

// Problem Statement: https://leetcode.com/problems/convert-bst-to-greater-tree

class Solution{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder){
       
        if(preorder.size() < 1)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        for(int i = 1; i < preorder.size(); i++){
            
            TreeNode* newNode = new TreeNode(preorder[i]);
            TreeNode* topp = nodes.top();
            
            if(topp->val > newNode->val){
                topp->left = newNode;
            }
            else{
                TreeNode* prev = nullptr;
                while(!nodes.empty() && nodes.top()->val < newNode->val){
                    prev = nodes.top();
                    nodes.pop();
                }
                prev->right = newNode;
            }
            nodes.push(newNode);
        }
        return root;
    }
};

/*
We are maintaining a decresing stack from bottom to top.

If element is smaller than top 
                -> it is left child of top
Else we will pop the element till (stack is empty or some bigger node is found) 
                -> it is right child of last popped node
*/
