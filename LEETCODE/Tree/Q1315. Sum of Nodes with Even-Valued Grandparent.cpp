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

// Problem Statement: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

class Solution{
public:
    int sumEvenGrandparent(TreeNode* node){
        if(!node)
            return 0;
        
        int sum = 0;
        if(node->val % 2 == 0)
            sum = getSum(node, 0);
        
        int l = sumEvenGrandparent(node->left);
        int r = sumEvenGrandparent(node->right);
        
        return (l + r + sum);
    }
    
    int getSum(TreeNode* node, int h){
        if(!node)
            return 0;
        
        if(h == 2)
            return node->val;
        
        int l = getSum(node->left, h + 1);
        int r = getSum(node->right, h + 1);
        
        return (l + r);    
    }
};

/*
    If current node if even
        get sum of its grand children which is at height (curr + 2)
        
    get sum of left subtree
    get sum of right subtree
    
    return sum of all three.
*/

