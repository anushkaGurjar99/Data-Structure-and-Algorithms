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

// Problem Statement: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inOrder(root, nums);
        return find(nums, k);
    }
    void inOrder(TreeNode* node, vector<int>& nums) {
        if (!node) return;
        inOrder(node->left, nums);
        nums.push_back(node->val);
        inOrder(node->right, nums);
    }
    bool find(vector<int> nums, int target){
        for (int i = 0, j = nums.size() - 1; i < j;) {
            int sum = nums[i] + nums[j];
            if (sum == target)
                return true;
            else if (sum < target)
                i++;
            else
                j--;
        }
        return false;
    }
};
