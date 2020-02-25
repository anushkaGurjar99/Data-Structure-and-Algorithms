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
// Problem Statement: https://leetcode.com/problems/deepest-leaves-sum

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxLevel = -1;
        getDeepestLeavesSum(root, sum, maxLevel, 0);
        return sum;
    }
    void getDeepestLeavesSum(TreeNode* node, int& sum, int& maxLevel, int currLevel){
        if(!node)
            return;
        currLevel++;
        
        getDeepestLeavesSum(node->left, sum, maxLevel, currLevel);
        getDeepestLeavesSum(node->right, sum, maxLevel, currLevel);
        
        if(currLevel > maxLevel){
            sum = node->val;
            maxLevel = currLevel;
        }
        else if(currLevel == maxLevel){
            sum += node->val;
        }
        else{}
    }
};


// ***************************** Iterative Solution *****************************
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        
        queue<TreeNode*> nodes;
        queue<TreeNode*> next;
        nodes.push(root);
        
        while(!nodes.empty()){
            TreeNode* temp = nodes.front();
            nodes.pop();
            sum += temp->val;
            
            if(temp->left){
                next.push(temp->left);
            }
            if(temp->right){
                next.push(temp->right);
            }
            
            if(nodes.empty()){
                swap(nodes,next);
                sum = (nodes.empty()) ? sum : 0;
            }
        }
        
        return sum;
    }
};
