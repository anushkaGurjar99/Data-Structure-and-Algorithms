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
