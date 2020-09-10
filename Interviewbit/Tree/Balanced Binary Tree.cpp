/*
 * Author : Anushka Gurjar
 * Date   : September 2020
 * flags  : -std=c++17
*/

#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.interviewbit.com/problems/balanced-binary-tree/

int helper(TreeNode* A, int& res){
    if(!A || !res)
        return 0;
        
    int l = helper(A->left, res) + 1;
    int r = helper(A->right, res) + 1;
    
    if(abs(l - r) > 1)
        res = 0;
    
    return max(l, r);
}

int Solution::isBalanced(TreeNode* A){
    int res = 1;
    helper(A, res);
    return res;
}
