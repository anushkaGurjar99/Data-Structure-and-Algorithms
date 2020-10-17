/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++17
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

// Problem Statement: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class Solution{
public:
    bool isCompleteTree(TreeNode* root){
        
        vector<TreeNode*> A;
        A.push_back(root);
        int i = 0;
        
        while(i < A.size() && A[i]){
            A.push_back(A[i]->left);
            A.push_back(A[i]->right);
            i++;
        }
        
        while(i < A.size() && !A[i])
            i++;
        
        return i == A.size();
    }
};

/*
Use BFS to do a level order traversal,
add childrens to the bfs queue,
until we met the first empty node.

For a complete binary tree, there should not be any node after we met an empty one.
*/
