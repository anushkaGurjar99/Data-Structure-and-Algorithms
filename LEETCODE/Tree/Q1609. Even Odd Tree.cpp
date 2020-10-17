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

// Problem Statement: https://leetcode.com/problems/even-odd-tree/

class Solution{
public:
    bool isEvenOddTree(TreeNode* root){
        int maxD = 1;
        unordered_map<int, int> m;
        return helper(root, m, 1);   
    }
    
    bool helper(TreeNode* node, unordered_map<int, int>& m, int l){
        if(!node)
            return true;
        
        bool odd = (l % 2 != 0);
        bool even = (l % 2 == 0);
        
        if(m.find(l) != m.end()){
            if(odd && m[l] >= node->val)          
                return false;
            if(even && m[l] <= node->val)         
                return false;
        }
        
        if(odd && node->val % 2 == 0)
            return false;
        if(even && node->val % 2 != 0)
            return false;
        
        m[l] = node->val;
        l++;
        
        return helper(node->left, m, l) && helper(node->right, m, l);   
    }
};

/*
    Increasing ODD
    Decreasing EVEN
    
    Maintain a map for Last-visited-node at each level
    Compare the Last-visited-node and current-node value & Odd-Even values of node
*/
