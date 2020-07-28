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

// Problem Statement: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
        
        unordered_map<TreeNode*, TreeNode*> m;
        getParentNode(root, nullptr, m);
        
        queue<TreeNode*> q;
        q.push(target);
        
        while(K--){
            for(int i = q.size(); i > 0; i--){
                TreeNode* curr = q.front();             
                
                if(m[curr]){                                // store parent and mark child visited
                    q.push(m[curr]);
                    m[curr] = nullptr;
                }
                
                if(m[curr->left]){                          // store left child and mark parent visted
                    q.push(curr->left);
                    m[curr->left] = nullptr;
                }
                
                if(m[curr->right]){                         // store right child and mark parent visited
                    q.push(curr->right);
                    m[curr->right] = nullptr;
                }
                
                q.pop();
            }
        }
        
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
                
        return result;
    }
    
    void getParentNode(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& m){
        if(!node)
            return;
        m[node] = parent;
        getParentNode(node->left, node, m);
        getParentNode(node->right, node, m);
    }
    
};

/*
Appraoch:
    pass1: store parent node of each nodes 
    
    pass2: use bfs to obtain K distance nodes
            we come to a node by its parent so we mark the parent visited
            OR
            we come to a node by its child so we mark the child visited         
*/
