/*
 * Author : Anushka Gurjar
 * Date   : August 2020
 * flags  : -std=c++14
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/least-common-ancestor/

int helper(TreeNode* A, int B, int C){
    if(!A)
        return -1;
    
    if(A->val == B || A->val == C)
        return A->val;
        
    int l = helper(A->left, B, C);
    int r = helper(A->right, B, C);
    
    if(l != -1 && r != -1)
        return A->val;
    
    return (l != -1 ? l : r);
}

bool isPresent(TreeNode* A, int& target){
    if(!A)
        return false;
        
    if(A->val == target)
        return true;
        
    return isPresent(A->left, target) || isPresent(A->right, target);
}

int Solution::lca(TreeNode* A, int B, int C){
    if(!isPresent(A, B) || !isPresent(A, C))
        return -1;
    return helper(A, B, C);
}

