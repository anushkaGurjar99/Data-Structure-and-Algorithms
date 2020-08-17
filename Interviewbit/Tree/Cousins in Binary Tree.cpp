/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/cousins-in-binary-tree/


vector<int> Solution::solve(TreeNode* A, int B){
    
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        vector<int> result;
        bool isFound = false;
        
        for(int i = q.size(); i > 0; i--){
            TreeNode* curr = q.front();
            q.pop();
            
            if((curr->left && curr->left->val == B) || (curr->right && curr->right->val == B)){
                isFound = true;
            }
            else{
                if(curr->left){
                    result.push_back(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right){
                    result.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }
        }
        if(isFound)
            return result;
    }
       
    return {};
}

// check each level sequentially, exclude the sibiling node of target.
