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
// Problem Statement: https://leetcode.com/problems/deepest-leaves-sum

class Solution {
public:
    int deepestLeavesSum(TreeNode* root){
        int result = 0;
        int level = -1;
        getDeepestLeavesSum(root, result, level, 0);
        return result;
    }
    
    void getDeepestLeavesSum(TreeNode* node, int& result, int& level, int current){
        if(!node)
            return;
        
        if(!node->left && !node->right){
            if(level < current){
                level = current;
                result = node->val;
            }
            else if(level == current){
                result += node->val;
            }
        }
        
        getDeepestLeavesSum(node->left, result, level, current + 1);
        getDeepestLeavesSum(node->right, result, level, current + 1);  
    }    
};

/*
Maintaina a levelMarker that shows target level of leaf node
    Whenever leaf node is detected :
        ->  If it satisfy the current deepest level, we sum it into result
        ->  If it does not, we update the levelMarker and result.
*/



// ***************************** Iterative Solution *****************************
class Solution {
public:
    int deepestLeavesSum(TreeNode* root){
        
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            result = 0;
            for(int i = q.size(); i > 0; i--){
                TreeNode* currNode = q.front();
                q.pop();
                result += currNode->val;
                
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
        }
        
        return result;
    }
};

// Level Order Traversal
