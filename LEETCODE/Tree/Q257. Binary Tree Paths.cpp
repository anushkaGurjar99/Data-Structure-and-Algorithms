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

// Problem Statement:https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> result;
        getBinaryTreePaths(root, "", result);
        return result;
    }
    void getBinaryTreePaths(TreeNode* node, string path, vector<string> &result){
        if(node){
            path += (path == "") ? to_string(node->val) : ("->" + to_string(node->val));
            if(!node->left && !node->right){
                result.push_back(path);
                return;
            }
            getBinaryTreePaths(node->left, path, result);
            getBinaryTreePaths(node->right, path, result);
        }
    }
};
