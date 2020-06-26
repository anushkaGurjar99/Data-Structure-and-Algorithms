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

// Problem Statement: https://leetcode.com/problems/find-mode-in-binary-search-tree
class Solution {
public:
    vector<int> findMode(TreeNode* root){
        vector<int> result;
        result.push_back(1);
        int count = 1;
        TreeNode* pre = new TreeNode(INT_MIN-1);
        findFrequency(root, result, count, pre);
        result.pop_back();
        return result;
    }
    void findFrequency(TreeNode* node, vector<int>& result, int& count, TreeNode*& pre){
        if(!node)
            return;
        
        findFrequency(node->left, result, count, pre);
        
        count = (pre && pre->val == node->val) ? ++count : 1;
        pre = node;
        
        if(count >= result[result.size() - 1])
            getMostFrequentElement(result, node->val, count);
        
        findFrequency(node->right, result, count, pre);
    }
    
    void getMostFrequentElement(vector<int>& result, int key, int count){
        int pos = result.size() - 1;
        if(count == result[result.size() - 1]){
            result.insert(result.begin() + pos, key);
        }
        else{
            result.clear();
            result.push_back(key);
            result.push_back(count);
        }
    }
};
