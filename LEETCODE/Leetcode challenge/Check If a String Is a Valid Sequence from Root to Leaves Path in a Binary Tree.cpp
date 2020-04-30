/*
 * Author : Anushka Gurjar
 * Date   : April 2020
 * flags    : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr){
        return findSequence(root, arr, 0);
    }
    
    bool findSequence(TreeNode* node, vector<int> arr, int i){
        if(i == arr.size() || !node || arr[i] != node->val)
            return false;
        if(i == arr.size() - 1 && (!node->left && !node->right))
            return true;
        
        return findSequence(node->left, arr, i+1) || findSequence(node->right, arr, i+1);
    }
};

/*
Approach:
  compare string from root node
  if root value is matched -> check next value in left subtree and right subtree
  else return false to parent call.
*/
