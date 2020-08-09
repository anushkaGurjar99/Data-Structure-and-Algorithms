/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/diagonal-traversal/


vector<int> Solution::solve(TreeNode* A){
    
    vector<int> result;
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        TreeNode* top = q.front();
        
        while(top){
            if(top->left)
                q.push(top->left);
            
            result.push_back(top->val);
            top = top->right;
        }
        
        q.pop();
    }
    
    return result;
}

/*
initially top = root;

    scan the top till its right most child
    while scanning keep storing the left child (if any) into queue.
*/

