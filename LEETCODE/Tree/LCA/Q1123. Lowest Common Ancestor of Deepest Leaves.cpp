/*
 * Author : Anushka Gurjar
 * Date   : July 2020
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
// Problem Statement: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    TreeNode* lcaDeepestLeaves(TreeNode* root){
        
        TreeNode* lca = root;
        int maxDepth = 0;
        
        backtrack(root, lca, maxDepth, 0);
        
        return lca;
    }
    
    int backtrack(TreeNode* node, TreeNode*& lca, int& maxDepth, int dep){
        if(!node)
            return 0;
        
        int left = 1 + backtrack(node->left, lca, maxDepth, dep + 1);
        int right = 1 + backtrack(node->right, lca, maxDepth, dep + 1);
        
        if(left == right && left + dep >= maxDepth){
            maxDepth = dep + left;
            lca = node;
        }
        
        return max(left, right);
    }    
};

/*
Observations:
    LCA of deepest leaves will definitely have leftHeight == rightHeight
                2
              /  \
             3    5
           /   \
          7     8               deepest leaves are 7, 8 and there LCA(3) is following the above condition.
          
         
                2
              /  \
             3    5
           /  
          7                    deepest leaves are 7 and there LCA(7) is following the above condition.
          
         
    
    There may exist a parent having leftHeight == rightHeight but it might not be the LCA
    So we need to maintain the height of Deepest node so that we can check the same for such subTree
    
                2
              /  \
             3    5
           /  \
          7    8                deepest leaves are 7 and there LCA(7) is following the above condition.
         
         Notice that 5 also has leftHeight == rightHeight 
         but it is not floowing the Property of Deepest leave so we ignore subtree of 5.
         
Note: we always pick the upper node follwing both conditions. (pick 3 instread of 7 and 8)
*/
