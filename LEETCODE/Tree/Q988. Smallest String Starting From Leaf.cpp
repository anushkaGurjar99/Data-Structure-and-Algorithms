/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
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

// Problem Statement: https://leetcode.com/problems/smallest-string-starting-from-leaf/

class Solution{
public:
    string smallestFromLeaf(TreeNode* root){
        string result;
        dfs(root, result, "");
        return result;
    }
    
    void dfs(TreeNode* node, string& res, string curr){
        
        if(!node)
            return;
        
        char c = node->val + 'a';
        curr.push_back(c);
        
        if(!node->left && !node->right){
            reverse(curr.begin(), curr.end());
            if(res == ""){
                res = curr;
                return;
            }
            
            bool flag = true;
            for(int i = 0; i < res.size() && i < curr.size(); i++){
                if(curr[i] < res[i]){
                    res = curr;
                    return;
                }
                if(curr[i] > res[i]){
                    flag = false;
                    break;
                }
            }  
            res = (flag) ? (res.size() < curr.size() ? res : curr) : res;
            
            return;
        }
        
        
        dfs(node->left, res, curr);
        dfs(node->right, res, curr);
    }
};
