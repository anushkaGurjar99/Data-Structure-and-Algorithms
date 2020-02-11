/*
 * Author : Anuska Gurjar
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
// Problem Statement: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

class Solution {
public:
    int min = INT_MAX;
    int secMin = INT_MAX;
    bool flag = 0;
    
    int findSecondMinimumValue(TreeNode* root){
        find(root);
        return (flag == 1) ? secMin : -1;
    }
    void find(TreeNode* node){
        if(node){
            if(node->val < min){
                secMin = min;
                min = node->val;
            }
            if(node->val > min && secMin >= node->val){
                secMin = node->val;
                flag = true;
            }            
            find(node->left);
            find(node->right);
        }
    }
};
