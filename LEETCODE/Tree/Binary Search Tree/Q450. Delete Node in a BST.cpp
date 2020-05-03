/*
 * Author : Anushka Gurjar
 * Date   : May 2020
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
// Problem Statement: https://leetcode.com/problems/delete-node-in-a-bst/

class Solution{
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        
        if(!root)
            return nullptr;
        
        if(root->val == key)
            return setSubTree(root);
        
        TreeNode* parent = nullptr;
        TreeNode* nodeToBeDeleted = searchKey(root, parent, key);
        
        if(nodeToBeDeleted){
            if(key < parent->val)
                parent->left = setSubTree(nodeToBeDeleted);
            else
                parent->right = setSubTree(nodeToBeDeleted);
        }
        return root;
    }
    
    TreeNode* searchKey(TreeNode* node, TreeNode*& parent, int key){
        if(!node)
            return nullptr;
        
        if(key == node->val)
            return node;
        
        parent = node;
        return key < node->val ? searchKey(node->left, parent, key): searchKey(node->right, parent, key);
    }
    
    TreeNode* setSubTree(TreeNode* node){
        if(node->left && node->right){
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            while(r->left)
                r = r->left;
            r->left = l;
        }
        return node->right ? node->right : (node->left) ? node->left : nullptr;
    }
};

/*

                    10
                5           20
             1     7            28
                  6   8
                x   y
                
delete (5)
                    10
                7           20
             6     8              8
           x   y         
         1      
                
Approach:
    search the key into BST. Also store it's parent node.  O(height) time
    
    if key not found
      return the root as it is
      
    if key is equal to root
        return updated node
            
    if key found and parent node is not null{
        if key is left node of parent
            update parent left
        else
            update parent right
    }
    
    
How would you update the node ?
  if node has both left and right child
      save node of left child into "t"
      set node->left node into left of node->right ("leftest of right child": all values of right child are greater than left chiild)
  
  if node has right child return right
  if node has left child return left
  else nullptr
*/





