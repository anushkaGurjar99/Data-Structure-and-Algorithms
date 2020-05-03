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
// Problem Statement: https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root){
        return getSum(root);
    }
    
    int getSum(TreeNode* node){
        if(!node)
            return 0;
        
        int sum = 0;
        if(node->left && !node->left->left && !node->left->right)
            sum += node->left->val;
        
        sum += getSum(node->left);
        sum += getSum(node->right);
             
        return sum;
    }
};

// ********************************************* By Reference **********************************************************

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root){
        int result = 0;
        getSum(root, result);
        return result;
    }
    
    void getSum(TreeNode* node, int& sum){
        if(!node)
            return;
        
        if(node->left && !node->left->left && !node->left->right)
            sum += node->left->val;
        
        getSum(node->left, sum);
        getSum(node->right, sum);   
    }
};
