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
// Problem Statement: https://leetcode.com/problems/minimum-absolute-difference-in-bst

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = nullptr;
        int res = INT_MAX;
        getMin(root, prev, res);
        return res;
    }
    void getMin(TreeNode* current, TreeNode*& prev, int& res){
        if(!current)
            return;
        getMin(current->left, prev, res);
        if(prev)
            res = min(res, (current->val - prev->val));
        prev = current;
        getMin(current->right, prev, res);
    }
};


// ****************************************** Morris InOrder Traversal Approach ******************************************
class Solution {
public:
    int getMinimumDifference(TreeNode* root){
        int result = INT_MAX;
        TreeNode* current = root;
        TreeNode* prev = nullptr;
        
        while(current){
            if(!current->left){
                if(prev)
                    result = min(result, current->val - prev->val);
                prev = current;
                current = current->right;
            }
            else{
                TreeNode* predecessor = current->left;
                while(predecessor->right && predecessor->right != current)
                    predecessor = predecessor->right;
                
                if(!predecessor->right){
                    predecessor->right = current;
                    current = current->left;
                }
                else{
                    predecessor->right = nullptr;
                    if(prev)
                        result = min(result, current->val - prev->val);
                    prev = current;
                    current = current->right;
                }
                
            }
        }
        
        return result;
    }
};
