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
// Problem Statement: https://leetcode.com/problems/insert-into-a-binary-search-tree

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
class Solution{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(!root)
            return new TreeNode(val);
        
        if(val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
            
        return root;
    }
};

/*
           4
       2        7
     1   3    5    8
                6
           
    (insert 6)
    
    Approach:
        we know that new node will be inserted at leaf of some node.
        so find a node which is suitable for new node using BST property.
        as soon as we find leaf node we return a newNode(val).
*/
/*
if val < root
    traverse left subtree (if null found, insert the node)
    
if val > root
    traverse right subtree (if null found, insert the node)
*/


// *************************************** Approach: Iterative ***************************************
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
        
        TreeNode* newNode = new TreeNode(val);
        if(!root)
            return newNode;
        
        TreeNode* trav = root;
        TreeNode* prev = nullptr;
        
        while(trav){
            prev = trav;
            trav = (val < trav->val) ? trav->left : trav->right;
        }
        
        if(val < prev->val)
            prev->left = newNode;
        else
            prev->right = newNode;
        
        return root;
    }
};

/*
Find the suitable leaf node(prev) according to BST property

Insert into leaf (eithrt right or left)
*/
