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
// Problem Statement: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.empty())
            return nullptr;
        return constructBST(nums, 0, nums.size() - 1);
    }
    TreeNode* constructBST(vector<int> nums, int left, int right){
        if(left > right)
            return nullptr;
        int mid = left + (right - left + 1) / 2;
        TreeNode* current = new TreeNode(nums[mid]);
        current->left = constructBST(nums, left, mid - 1);
        current->right = constructBST(nums, mid + 1, right);
        return current;
    }
};

// ********************************* One Function Approach *********************************

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.empty())
            return nullptr;
        if(nums.size() == 1)
            return (new TreeNode(nums[0]));
        
        int mid = nums.size() / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        vector<int> left(nums.begin(), nums.begin() + mid );
        vector<int> right(nums.begin() + mid + 1, nums.end());
        
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        
        return root;
    }
};
